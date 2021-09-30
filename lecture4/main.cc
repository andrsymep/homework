#include <string>
#include <iostream>

#include "failure.hh"
#include "database.hh"

using namespace std;

void add_failure(database &db)
{
  failure failure;

  cout << "Enter ID: ";
  cin >> failure.id;
  cout << "Enter model: ";
  cin >> failure.model;
  cout << "Enter description: ";
  cin >> failure.description;
  cout << "Enter symptoms: ";
  cin >> failure.symptoms;
  cout << "Enter repairs: ";
  cin >> failure.repairs;
  cout << "Enter price: ";
  cin >> failure.price;

  cout << "Enter number of parts: ";
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cout << "Enter number of part #" << i << ": ";
    int number;
    cin >> number;
    failure.parts.push_back(number);
  }

  db.add_failure(failure);
  cout << "Added new failure entry!" << endl;
}

void list_failures(database &db)
{
  auto &failures = db.get_failures();
  for (auto failure = failures.begin(); failure != nullptr; failure = failure->next)
  {
    const auto &data = failure->data;
    cout << "Failure #" << data.id << endl;
    cout << "Model " << data.model << endl;
    cout << "Description " << data.description << endl;
    cout << "Symptoms " << data.symptoms << endl;
    // ...
    cout << endl;
  }
}

int main()
{
  database db;

  while (true)
  {
    cout << endl
         << "Select:\n1 - Add failure\n2 - List failures\n3 - Delete failure\n";
    char c;
    cin >> c;

    switch (c)
    {
    case '1':
    {
      add_failure(db);
      break;
    }
    case '2':
    {
      list_failures(db);
      break;
    }
    case '3':
    {
      cout << "Failure ID to delete: ";
      int id;
      cin >> id;
      db.delete_failure(id);
      break;
    }
    default:
    {
      cout << "Invalid option" << endl;
      break;
    }
    }
  }
}