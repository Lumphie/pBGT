#ifndef INT_EDGE_H
#define INT_EDGE_H

#include<boost/graph/adjacency_list.hpp>
#include<indiv_graph.h>

edg_desc
add_int_edge(
    const vert_desc& vd_from,
    const vert_desc& vd_to,
    const int i,
    indiv_graph& g
    );

int get_int_edge(const edg_desc& ed, const graph& g) noexcept;

#endif // INT_EDGE_H
