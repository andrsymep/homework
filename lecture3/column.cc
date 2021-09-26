#include "column.hh"

using namespace std;

size_t column::size() const
{
  size_t res = header.size();
  for (const auto &s : data)
  {
    res = std::max(res, s.size());
  }
  return res;
}