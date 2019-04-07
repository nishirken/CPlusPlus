#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
// #include "print-vector.h"
using namespace std;

vector<string> split(const string& str, const char& delim) {
  vector<string> acc;
  string temp;
  for (const char& c : str) {
    if (c == delim) {
      acc.push_back(temp);
      temp = "";
      continue;
    }
    temp.push_back(c);
  }
  acc.push_back(temp);
  return acc;
}

struct Student {
  string name;
  string surname;
  string birthDay;
  string birthMonth;
  string birthYear;
};

int main() {
  int Q;
  cin >> Q;
  vector<string> studentData(Q);
  vector<Student> students;
  string s;
  getline(cin, s);

  for (string& c : studentData) {
    getline(cin, c);
  }

  for (auto sd : studentData) {
    vector<string> splitted = split(sd, ' ');
    students.push_back(
      {splitted[0], splitted[1], splitted[2], splitted[3], splitted[4]}
    );
  }
  int queryLines;
  cin >> queryLines;
  getline(cin, s);
  vector<string> commands(queryLines);

  for (string& c : commands) {
    getline(cin, c);
  }

  for (auto command : commands) {
    vector<string> splitted = split(command, ' ');
    string cmd = splitted[0];

    if (cmd != "name" && cmd != "date") {
      cout << "bad request" << endl;
      continue;
    }

    int num = stoi(splitted[1]) - 1;

    if (num < 0 || num > Q - 1) {
      cout << "bad request" << endl;
      continue;
    }

    Student currentStudent = students[num];
    if (cmd == "name") {
      cout << currentStudent.name << " " << currentStudent.surname << endl;
    } else if (cmd == "date") {
      cout << currentStudent.birthDay << "." << currentStudent.birthMonth
      << "." << currentStudent.birthYear << endl;
    }
  }

  return 0;
}
