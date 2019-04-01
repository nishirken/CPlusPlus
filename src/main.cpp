#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
// #include "print-vector.h"
using namespace std;

void PrintIntVector(const std::vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i != v.size() - 1) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
}

void PrintStringVector(const std::vector<std::string>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i != v.size() - 1) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
}

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

string toLowerStr(const string& str) {
    string temp;
    for (auto const& c : str) {
        temp.push_back(tolower(c));
    }
    return temp;
}

int main() {
    string input;
    getline(cin, input);
    vector<string> splitted = split(input, ' ');

    sort(splitted.begin() + 1, splitted.end(), [](string i, string j) { return toLowerStr(i) < toLowerStr(j); });

    PrintStringVector(vector<string>(splitted.begin() + 1, splitted.end()));

    return 0;
}
