#include "indiv_graph.h"
#include <boost/graph/adjacency_list.hpp>
#include "sado_individual.h"
#include "sado_parameters.h"

indiv_graph
create_empty_directed_individual_graph() noexcept
{
  return {};
}

template <typename graph, typename individual_vertex>
typename boost::graph_traits<graph>::vertex_descriptor
add_individual_vertex(const individual_vertex& v, graph& g) noexcept
{
  static_assert(!std::is_const<graph>::value, "graph cannot be const");
  const auto vd = boost::add_vertex(g);
  g[vd] = v;
  return vd;
}

indiv_graph
create_my_individual_graph() noexcept
{
  auto g = create_empty_directed_individual_graph();
  const sado::parameters p = sado::create_golden_standard_parameters();

  const sado::indiv mother;
  const sado::indiv father;
  const sado::indiv kid = sado::create_offspring(mother, father, p);

  const auto vd_a = add_individual_vertex(mother, g);
  const auto vd_b = add_individual_vertex(father, g);
  const auto vd_c = add_individual_vertex(kid, g);
  boost::add_edge(vd_a, vd_c, g);
  boost::add_edge(vd_b, vd_c, g);
  return g;

}

indiv_graph create_graph_from_population(const std::vector<sado::indiv>& pop) noexcept
{
  auto g = create_empty_directed_individual_graph();

  using vertex_des = typename boost::graph_traits<indiv_graph>::vertex_descriptor;

  std::vector<std::pair<int, vertex_des>> v;
  for(int i = 0; i != static_cast<int>(pop.size()); ++i)
  {
    const auto vd = add_individual_vertex(pop[i], g);
    const std::pair<int, vertex_des>
        vd_pair{i, vd};
    v.push_back(vd_pair);
  }

  for (const std::pair<int, vertex_des> pair : v)
  {
    for(int j = 0; j != static_cast<int>(pop.size()); ++j)
    {
      if (pop[pair.first].get_father_id() == pop[j].get_id()
          || pop[pair.first].get_mother_id() == pop[j].get_id())
        boost::add_edge(v[j].second, pair.second, g);
    }
  }

  return g;
}
