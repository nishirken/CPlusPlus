#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
// #include "print-vector.h"
using namespace std;

class Person {
  public:
    Person(const string& firstName, const string& lastName, const int& age) {
      birnAge = age;
      ChangeFirstName(age, firstName);
      ChangeLastName(age, lastName);
    }

    void ChangeFirstName(int year, const string& first_name) {
      if (year < birnAge) {
        return;
      }
      storageFirstNames[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
      if (year < birnAge) {
        return;
      }
      storageLastNames[year] = last_name;
    }

    string GetFullName(int year) const {
      if (year < birnAge) {
        return "No person";
      }
      string firstName = GetName(year, storageFirstNames);
      string lastName = GetName(year, storageLastNames);

      return FullName(firstName, lastName);
    }

    string GetFullNameWithHistory(int year) const {
      if (year < birnAge) {
        return "No person";
      }

      string firstName = GetHistoryName(year, storageFirstNames);
      string lastName = GetHistoryName(year, storageLastNames);

      return FullName(firstName, lastName);
    }

  private:
    map<int, string> storageFirstNames;
    map<int, string> storageLastNames;
    int birnAge;

    string FullName(const string& firstName, const string& lastName) const {
      if (firstName == "" && lastName == "") {
        return "Incognito";
      }

      if (lastName == "") {
        return firstName + " with unknown last name";
      } else if (firstName == "") {
        return lastName + " with unknown first name";
      }
      return firstName + " " + lastName;
    }

    string GetName(const int& year, map<int, string> storage) const {
      for (int i = year; i != 0; i--) {
        if (storage.count(i)) {
          return storage[i];
        }
      }
      return "";
    }

    string GetHistoryName(const int& year, map<int, string> storage) const {
      vector<string> tempNames;
      for (int i = year; i != 0; i--) {
        if (storage.count(i)) {
          if (tempNames.size() != 0 && tempNames[tempNames.size() - 1] == storage[i]) {
            continue;
          }
          tempNames.push_back(storage[i]);
        }
      }
      int size = tempNames.size();
      if (size == 0) {
        return "";
      } else if (size == 1) {
        return tempNames[0];
      } else if (size == 2) {
        tempNames[0] + " " + "(" + tempNames[1] + ")";
      }
        string temp = tempNames[0] + " " + "(";
        for (int i = 1; i != size; i++) {
          temp += (tempNames[i] + ", ");
        }
        temp.pop_back();
        temp.pop_back();
        temp += ")";
        return temp;
    }
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
