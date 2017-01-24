#ifndef SADO_PEDIGREE_H
#define SADO_PEDIGREE_H

#include <vector>
#include "sado_individual.h"
#include "sado_graph.h"

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include "count_directed_graph_connected_components.h"
#include "convert_dot_to_svg.h"
#include "convert_svg_to_png.h"
#include "count_max_number_of_pieces.h"


namespace sado {

class pedigree
{
public:
  pedigree();
  void add(const indiv& i);
  bool are_related(const indiv& a, const indiv& b) const ;
  bool empty() const noexcept;
  void end_gen();

private:
  std::vector<indiv> m_v;
  std::vector<std::vector<indiv>> m_generations;
  sado::sado_graph m_g;

  void add_gen(const std::vector<indiv>& gen);
  void connect_gen();

  friend bool operator==(const pedigree& lhs, const pedigree& rhs) noexcept;
};

bool operator==(const pedigree& lhs, const pedigree& rhs) noexcept;
bool operator!=(const pedigree& lhs, const pedigree& rhs) noexcept;

} //~namespace sado

#endif // SADO_PEDIGREE_H


/*
int kewe::count_good_species(
    const individuals& pop,
    const simulation_parameters& parameters
    )
{
  if (pop.empty()) return 0;
  if (static_cast<int>(pop.size()) == 1) return 1;

  const attractivenesses as{calc_attractivenesses(pop, parameters)};

  genotype_graph g;
  add_vertices(pop, g);
  add_edges(as, g, parameters);


  { //Don't run in travis!!!
    // Create picture of all genotypes and their connections
    const std::string dot_filename{"kewe_count_good_species.dot"};
    const std::string svg_filename{"kewe_count_good_species.svg"};
    const std::string png_filename{"kewe_count_good_species.png"};
    std::ofstream f(dot_filename);
    boost::write_graphviz(f, g,
      [g](std::ostream& os, const auto iter)
      {
        os << "[label=\"" << g[iter] << "\"]";
      }
    );
    f.close();
    convert_dot_to_svg(dot_filename, svg_filename);
    convert_svg_to_png(svg_filename, png_filename);
    std::system("display kewe_count_good_species.png");
  }

  return count_undirected_graph_connected_components(g);
}
*/
