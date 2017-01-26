#include "individual_vertex.h"
#include <boost/graph/adjacency_list.hpp>
#include "sado_individual.h"

vert_desc add_individual_vertex(const sado::indiv& i, indiv_graph& g) noexcept
{
  static_assert(!std::is_const<indiv_graph>::value, "graph cannot be const");
  const auto vd = boost::add_vertex(g);
  g[vd] = i;
  return vd;
}

std::vector<sado::indiv> get_individual_vertexes(const indiv_graph& g) noexcept
{
  using vd = typename graph::vertex_descriptor;
  std::vector<sado::indiv> v(boost::num_verticees(g));
  const auto vip = vertices(g);
  std::transform(vip.first, vip.second, std::begin(v), [g](const vd& d) {return g[d];});
}
