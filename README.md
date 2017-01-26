# pBGT
Here I will practice with the Boost Graph Tutorial

# Create a graph from a population
![alt text](https://github.com/Lumphie/pBGT/blob/master/test.png "It can create graphs from a sado::population")

### How to:

Use create_graph_from_population(const std::vector\<sado::indiv>& pop).
Save it to a const auto variable.

save_graph_to_dot(g, "filename.dot")

convert_dot_to_svg("filename.dot", "filename.svg")

convert_svg_to_png("filename.svg", "filename.png")
