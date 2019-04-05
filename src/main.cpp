#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
// #include "print-vector.h"
using namespace std;

struct Specialization {
  string value;
  explicit Specialization(const string& newValue) {
    value = newValue;
  }
};

struct Course {
  string value;
  explicit Course(const string& newValue) {
    value = newValue;
  }
};

struct Week {
  string value;
  explicit Week(const string& newValue) {
    value = newValue;
  }
};

struct LectureTitle {
  string specialization;
  string course;
  string week;

  explicit LectureTitle(const Specialization& spec, const Course& c, const Week& w) {
    specialization = spec.value;
    course = c.value;
    week = w.value;
  }
};

int main() {
  LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
  );
  return 0;
}
