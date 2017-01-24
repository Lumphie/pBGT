#include "sado_pedigree.h"

sado::pedigree::pedigree()
{

}

void sado::pedigree::add(const indiv& i)
{
  m_v.push_back(i);
}

void sado::pedigree::add_gen(const std::vector<indiv>& gen)
{
  m_generations.push_back(gen);
}

bool sado::pedigree::are_related(const indiv& /* a */, const indiv& /* b */) const
{
  return false;
}

void sado::pedigree::connect_gen()
{
  std::vector<indiv> this_gen = m_generations.back();
  std::vector<indiv> past_gen = m_generations.at(m_generations.size()-1);

  //add_vertices(this_gen, m_g);
 // add_edges(this_gen, past_gen, m_g);
  //add_edges(as, m_g, parameters);

}

void sado::pedigree::end_gen()
{

}


bool sado::pedigree::empty() const noexcept
{
  return m_v.empty();
}



bool sado::operator==(const pedigree& lhs, const pedigree& rhs) noexcept
{
  return lhs.m_v == rhs.m_v;
}

bool sado::operator!=(const pedigree& lhs, const pedigree& rhs) noexcept
{
  return !(lhs == rhs);
}

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
