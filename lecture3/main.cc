#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <iomanip>

#include "table.hh"

using namespace std;

struct student
{
  string name, surname;
  float average_mark;
  int attended_lessons;
};

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cout << "Two arguments are expected" << endl;
    return 1;
  }

  vector<student> students;

  {
    ifstream fin(argv[1], ios_base::in);
    string str;
    while (getline(fin, str))
    {
      istringstream ss(str);
      student st;

      getline(ss, st.name, ',');
      getline(ss, st.surname, ',');
      ss >> st.average_mark;
      ss.ignore();
      ss >> st.attended_lessons;
      ss.ignore();
      ss.ignore();

      students.push_back(st);
    }
  }

  table table = {{
      column{"Succeeded", {}, TextAlignment::CENTER},
      column{"Name", {}, TextAlignment::LEFT},
      column{"Surname", {}, TextAlignment::LEFT},
      column{"Avg mark", {}, TextAlignment::RIGHT},
      column{"Attended", {}, TextAlignment::CENTER},
  }};

  for (const auto &student : students)
  {
    table.columns[0].data.push_back(student.average_mark > 4 && student.attended_lessons > 5 ? "+" : " ");
    table.columns[1].data.push_back(student.name);
    table.columns[2].data.push_back(student.surname);

    ostringstream oss;
    oss << setprecision(2) << fixed << student.average_mark;
    table.columns[3].data.push_back(oss.str());

    table.columns[4].data.push_back(to_string(student.attended_lessons));
  }

  cout << table;
}