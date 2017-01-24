#include "sado_graph.h"

#include "create_empty_directed_graph.h"

#include "sado_parameters.h"
#include "sado_individual.h"
#include <vector>

boost::adjacency_list<>
create_family_tree_test() noexcept
{
  sado::parameters p = sado::create_golden_standard_parameters();;
  sado::indiv mother;
  sado::indiv father;
  sado::create_offspring(mother, father, p);

  auto g = create_empty_directed_graph();
  const auto vd_m = boost::add_vertex(g);
  const auto vd_f = boost::add_vertex(g);
  const auto vd_kid = boost::add_vertex(g);
  boost::add_edge(vd_m, vd_kid, g);
  boost::add_edge(vd_f, vd_kid, g);

  return g;
}
