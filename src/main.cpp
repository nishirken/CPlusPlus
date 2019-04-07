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

int main() {
  ifstream input("input.txt");

  string line;
  if (input) {
    cout << fixed << setprecision(3);
    while (getline(input, line)) {
      cout << stod(line) << endl;
    }
  }
  return 0;
}
