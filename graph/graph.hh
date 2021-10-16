#pragma once

#include <vector>
#include <functional>

class graph
{
public:
  using vertex_index = std::size_t;
  using iter_callback = std::function<void(vertex_index)>;

  graph(std::size_t vertex_count);

  void add_edge(vertex_index from, vertex_index to, size_t distance);

  void dfs(vertex_index start, iter_callback callback);
  void bfs(vertex_index start, iter_callback callback);

  size_t distance_between(vertex_index v1, vertex_index v2);

private:
  struct edge
  {
    vertex_index vertex;
    size_t distance;
  };

  std::vector<std::vector<edge>> edges;
  std::size_t vertex_count;

  void recursive_dfs_(iter_callback callback, std::vector<bool> &used, vertex_index vertex);
};