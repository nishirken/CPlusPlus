#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
// #include "print-vector.h"
using namespace std;

class ReversibleString {
  public:
    ReversibleString() {
      str = "";
    }
    ReversibleString(const string& x) {
      str = x;
    }

    void Reverse() {
      if (str == "") {
        return;
      }

      vector<char> reversed;
      int lastIndex = str.length() - 1;
      for (int i = lastIndex; i >= 0; i--) {
        reversed.push_back(str[i]);
      }
      str = string(reversed.begin(), reversed.end());
    }

    string ToString() const {
      return str;
    }

  private:
    string str;
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}
