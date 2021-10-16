#include <iostream>
#include <fstream>

#include "graph.hh"
#include "graph_reader.hh"

using namespace std;

int main()
{
  ifstream fin("graph.txt", ios_base::in);

  graph g = read_graph(fin);

  cout << "dfs: ";
  g.dfs(0, [](auto vertex)
        { cout << vertex << " "; });
  cout << endl;

  cout << "bfs: ";
  g.bfs(0, [](auto vertex)
        { cout << vertex << " "; });
  cout << endl;

  cout << "dijkstra: " << g.distance_between(0, 4) << endl;
}