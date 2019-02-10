#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsPalindrom(string xs) {
    string reversed = "";
    for (int i = xs.length() - 1; i >= 0; i--) {
        reversed.push_back(xs[i]);
    }
    return reversed == xs;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> temp = {};
    for (string word : words) {
        if ((word.length() >= minLength) && IsPalindrom(word)) {
            temp.push_back(word);
        }
    }
    return temp;
}

void printBool(bool x) {
    if (x) {
        cout << "true";
    } else {
        cout << "false";
    }
}

string Replace(string str, char from, char to) {
    for (char s : str) {
        if (s == from) {
            s = to;
        }
    }
    return str;
}

vector<string> Split(string str, char at) {
    vector<string> res = {};
    string temp = "";
    for (char c : str) {
        if (c == at) {
            res.push_back(temp);
            temp = "";
            continue;
        }
        temp.push_back(c);
    }
    return res;
}

void printVector(vector<string> words) {
    for (string word : words) {
        cout << word << ", ";
    }
}

int main() {
    string xs;
    int minLength;
    cin >> xs >> minLength;
//    cout << PalindromFilter(Split(Replace(xs, ' ', '\0'), ','), minLength);
    return 0;
}