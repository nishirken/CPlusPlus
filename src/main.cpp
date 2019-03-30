#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
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

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> temp;
    for (auto const& x : m) {
        temp.insert(x.second);
    }
    return temp;
}

// void executeCommand(string command) {
//     set<string> values = BuildMapValuesSet({
//         {1, "odd"},
//         {2, "even"},
//         {3, "odd"},
//         {4, "even"},
//         {5, "odd"}
//     });
//     for (const string& value : values) {
//         cout << value << endl;
//     }
// }

// int main() {
//     int Q;
//     cin >> Q;
//     vector<string> commands(Q);
//     string s;
//     getline(cin, s);
//     if (Q == 0) {
//         return 0;
//     }

//     for (string& c : commands) {
//         getline(cin, c);
//     }

//     for (auto command : commands) {
//         executeCommand(command);
//     }

//     return 0;
// }
