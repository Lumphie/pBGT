#ifndef SADO_GRAPH_H
#define SADO_GRAPH_H

#include <boost/graph/adjacency_list.hpp>

#include "sado_individual.h"

namespace sado {

using sado_graph
  = boost::adjacency_list<
      boost::vecS,
      boost::vecS,
      boost::directedS, //parents -> offspring
      indiv //vertex type
      //edge type
    >;


} //~namespace sado

#endif // SADO_GRAPH_H
