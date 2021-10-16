#include "graph_reader.hh"

using namespace std;

graph read_graph(istream &is)
{
  size_t vertices, edges;
  is >> vertices >> edges;

  graph g(vertices);
  for (size_t i = 0; i < edges; i++)
  {
    size_t u, v, distance;
    is >> u >> v >> distance;
    g.add_edge(u, v, distance);
  }

  return g;
}