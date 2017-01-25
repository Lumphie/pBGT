#ifndef INDIVIDUAL_VERTEX_H
#define INDIVIDUAL_VERTEX_H

#include <boost/graph/adjacency_list.hpp>
#include "sado_individual.h"
#include "indiv_graph.h"

vert_desc add_individual_vertex(const sado::indiv& v, indiv_graph& g) noexcept;

#endif // INDIVIDUAL_VERTEX_H
