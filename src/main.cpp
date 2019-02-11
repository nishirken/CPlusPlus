#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> reversed;
    for (int i = v.size() - 1; i >= 0; i--) {
        reversed.push_back(v[i]);
    }
    return reversed;
}

//void PrintVector(const vector<int>& v) {
//    for (int i = 0; i < v.size(); i++) {
//        cout << v[i];
//        if (i != v.size()) {
//            cout << ' ';
//        }
//    }
//    cout << endl;
//}

int main() {
//    vector<int> numbers = {1, 5, 3, 4, 2};
//    vector<int> numbers1 = {1, 5, 3, 4, 2, 7};
//    vector<int> numbers2;
//    vector<int> reversed = Reversed(numbers);
//    PrintVector(reversed);
//    PrintVector(Reversed(numbers1));
//    PrintVector(Reversed(numbers2));
    return 0;
}