#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
// #include "print-vector.h"
using namespace std;

class SortedStrings {
  public:
    void AddString(const string& s) {
      storage.push_back(s);
    }
    vector<string> GetSortedStrings() {
      vector<string> temp = storage;
      sort(temp.begin(), temp.end());
      return temp;
    }

  private:
    vector<string> storage;
};
// void PrintSortedStrings(SortedStrings& strings) {
//   for (const string& s : strings.GetSortedStrings()) {
//     cout << s << " ";
//   }
//   cout << endl;
// }

int main() {
  // SortedStrings strings;
  
  // strings.AddString("first");
  // strings.AddString("third");
  // strings.AddString("second");
  // PrintSortedStrings(strings);
  
  // strings.AddString("second");
  // PrintSortedStrings(strings);
  
  return 0;
}
