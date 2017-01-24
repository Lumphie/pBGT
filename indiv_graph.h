#ifndef INDIV_GRAPH_H
#define INDIV_GRAPH_H

#include <boost/graph/adjacency_list.hpp>
#include "sado_individual.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  sado::indiv
>
create_empty_directed_individual_graph() noexcept;

template <typename graph, typename individual_vertex>
typename boost::graph_traits<graph>::vertex_descriptor
add_individual_vertex(const individual_vertex& v, graph& g) noexcept;

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  sado::indiv
>
create_my_individual_graph() noexcept;


#endif // INDIV_GRAPH_H
