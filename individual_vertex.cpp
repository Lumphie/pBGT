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
