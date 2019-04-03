#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
// #include "print-vector.h"
using namespace std;

class Person {
  public:
    void ChangeFirstName(int year, const string& first_name) {
      storageFirstNames[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
      storageLastNames[year] = last_name;
    }

    string GetFullName(int year) {
      string firstName = GetName(year, storageFirstNames);
      string lastName = GetName(year, storageLastNames);

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

  private:
    map<int, string> storageFirstNames;
    map<int, string> storageLastNames;

    string GetName(int year, map<int, string> storage) {
      for (int i = year; i != 0; i--) {
        if (storage.count(i)) {
          return storage[i];
        }
      }
      return "";
    }
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}
