#include <iostream>
#include <cassert>


#include "indiv_graph.h"
#include "sado_individual.h"
#include "sado_parameters.h"
#include "save_graph_to_dot.h"
#include "convert_dot_to_svg.h"
#include "convert_svg_to_png.h"

int main()
{
  std::vector<sado::indiv> pop;
  for(int i = 0; i != 10; ++i)
  {
    const sado::indiv indiv;
    pop.push_back(indiv);

  }

  const auto p = sado::create_golden_standard_parameters();
  for(int i = 0; i != 100; ++i)
  {
    int m = i;
    int f = 2*i;
    while(f >= static_cast<int>(pop.size()))
      f -= i/3;
    while (m>= static_cast<int>(pop.size()))
      m -= i/2;

    assert(m >= 0); assert(m < static_cast<int>(pop.size()));
    assert(f >= 0); assert(f < static_cast<int>(pop.size()));

    if(pop[m].get_id() != pop[f].get_id())
    {
      std::cout << m<< ' ' << f << '\n';
      const sado::indiv kid = sado::create_offspring(pop[m], pop[f], p);
      pop.push_back(kid);
    }

  }

  auto g = create_graph_from_population(pop);
  save_graph_to_dot(g, "test.dot");
  convert_dot_to_svg("test.dot", "test.svg");
  convert_svg_to_png("test.svg", "test.png");
}
