#include "indiv_graph.h"
#include <boost/graph/adjacency_list.hpp>
#include "sado_individual.h"
#include "sado_parameters.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  sado::indiv
>
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

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  sado::indiv
>
create_my_individual_graph() noexcept
{
  auto g = create_empty_directed_individual_graph();
  const sado::parameters p = sado::create_golden_standard_parameters();

  const sado::indiv mother();
  const sado::indiv father();
  const sado::indiv kid = sado::create_offspring(mother, father, p);

  const auto vd_a = add_individual_vertex(mother, g);
  const auto vd_b = add_individual_vertex(father, g);
  const auto vd_c = add_individual_vertex(kid, g);
  boost::add_edge(vd_a, vd_c, g);
  boost::add_edge(vd_b, vd_c, g);
  return g;

}
