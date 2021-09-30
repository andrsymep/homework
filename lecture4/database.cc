#include "failure.hh"
#include "database.hh"

void database::add_failure(failure failure)
{
  failures.push_back(failure);
}

void database::delete_failure(int id)
{
  for (auto failure = failures.begin(); failure != nullptr; failure = failure->next)
  {
    const auto &data = failure->data;
    if (data.id == id)
    {
      failures.erase(failure);
      return;
    }
  }
}

const linked_list<failure> &database::get_failures()
{
  return failures;
}