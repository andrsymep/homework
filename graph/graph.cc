#include <queue>
#include <set>
#include <limits>
#include <utility>

#include "graph.hh"

using namespace std;

graph::graph(size_t vertex_count) : vertex_count(vertex_count)
{
  edges.resize(vertex_count);
};

void graph::add_edge(vertex_index from, vertex_index to, size_t distance)
{
  edges[from].push_back({to, distance});
}

void graph::dfs(vertex_index start, iter_callback callback)
{
  vector<bool> used(vertex_count);
  recursive_dfs_(callback, used, start);
}

void graph::bfs(vertex_index start, iter_callback callback)
{
  vector<bool> used(vertex_count);
  queue<vertex_index> q;
  q.push(start);

  while (!q.empty())
  {
    vertex_index vertex = q.front();
    q.pop();
    used[vertex] = true;

    callback(vertex);

    for (auto [next, _] : edges[vertex])
    {
      if (used[next])
      {
        continue;
      }

      q.push(next);
    }
  }
}

size_t graph::distance_between(vertex_index v1, vertex_index v2)
{
  vector<size_t> dist(vertex_count, numeric_limits<size_t>::max());
  set<pair<size_t, vertex_index>> s;

  dist[v1] = 0;
  s.insert({0, v1});

  while (!s.empty())
  {
    auto [_, vertex] = *s.begin();

    for (auto [next, distance] : edges[vertex])
    {
      if (dist[next] > dist[vertex] + distance)
      {
        s.erase({dist[next], next});
        dist[next] = dist[vertex] + distance;
        s.insert({dist[next], next});
      }
    }

    s.erase({dist[vertex], vertex});
  }

  return dist[v2];
}

void graph::recursive_dfs_(iter_callback callback, vector<bool> &used, vertex_index vertex)
{
  used[vertex] = true;

  callback(vertex);

  for (auto [next, _] : edges[vertex])
  {
    if (used[next])
    {
      continue;
    }

    recursive_dfs_(callback, used, next);
  }
}
