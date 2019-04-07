#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
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

int main() {
  ifstream input("input.txt");

  string line;
  if (input) {
    getline(input, line);
    vector<string> splitted(split(line, ' '));
    vector<vector<string>> data;
    
    while(getline(input, line)) {
      vector<string> stringData = split(line, ',');
      vector<string> l;
      for (auto const& s : stringData) {
        l.push_back(s);
      }
      data.push_back(l);
    }

    for (auto const& d : data) {
      for (int i = 0; i != d.size(); i++) {
        cout << setw(10) << d[i];
        if (i < d.size() - 1) {
          cout << " ";
        }
      }
      cout << endl;
    }
  }
  return 0;
}
