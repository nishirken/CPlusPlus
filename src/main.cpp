#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
// #include "print-vector.h"
using namespace std;

class Incognizable {
  public:
    Incognizable() {}
    Incognizable(const int& x) {}
    Incognizable(const int& x, const int& y) {}
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}
