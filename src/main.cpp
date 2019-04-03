#include <algorithm>
#include <iostream>
#include <string>
#include <map>
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

      return FullName(firstName, lastName);
    }

    string GetFullNameWithHistory(int year) {
      string firstName = GetHistoryName(year, storageFirstNames);
      string lastName = GetHistoryName(year, storageLastNames);

      return FullName(firstName, lastName);
    }

  private:
    map<int, string> storageFirstNames;
    map<int, string> storageLastNames;

    string FullName(const string& firstName, const string& lastName) {
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

    string GetName(const int& year, map<int, string> storage) {
      for (int i = year; i != 0; i--) {
        if (storage.count(i)) {
          return storage[i];
        }
      }
      return "";
    }

    string GetHistoryName(const int& year, map<int, string> storage) {
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
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}
