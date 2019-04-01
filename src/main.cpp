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
    string input;
    getline(cin, input);
    vector<string> splitted = split(input, ' ');
    vector<int> numbers;

    for (auto const& x : splitted) {
        numbers.push_back(stoi(x));
    }

    sort(numbers.begin() + 1, numbers.end(), [](int i, int j) { return abs(i) < abs(j); });

    PrintIntVector(vector<int>(numbers.begin() + 1, numbers.end()));

    return 0;
}
