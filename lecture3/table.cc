#include "column.hh"
#include "table.hh"

using namespace std;

void print_aligned(std::ostream &os, const string &s, size_t size, TextAlignment alignment)
{
  switch (alignment)
  {
  case TextAlignment::LEFT:
  {
    os << s;
    for (int i = 0; i < size - s.size(); i++)
    {
      os << ' ';
    }
    break;
  }
  case TextAlignment::CENTER:
  {
    int i = 0;
    for (; i < (size - s.size()) / 2; i++)
    {
      os << ' ';
    }
    os << s;
    for (; i < size - s.size(); i++)
    {
      os << ' ';
    }
    break;
  }
  case TextAlignment::RIGHT:
  {
    for (int i = 0; i < size - s.size(); i++)
    {
      os << ' ';
    }
    os << s;
    break;
  }
  }
}

std::ostream &operator<<(std::ostream &os, const table &table)
{
  for (const auto &column : table.columns)
  {
    print_aligned(os, column.header, column.size(), column.alignment);
    os << ' ';
  }
  os << endl;

  for (int i = 0; i < table.columns[0].data.size(); i++)
  {
    for (const auto &column : table.columns)
    {
      print_aligned(os, column.data.at(i), column.size(), column.alignment);
      os << ' ';
    }
    os << endl;
  }
  return os;
}