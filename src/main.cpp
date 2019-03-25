#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
// #include "print-vector.h"
using namespace std;

string isAnagram(string first, string second) {
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    if (first == second) {
        return "YES";
    } else {
        return "NO";
    }
}

string getLast(string inputStr) {
    string temp;
    int i = inputStr.length() - 1;

    for (i; inputStr[i] != ' '; i--) {
        temp.push_back(inputStr[i]);
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

string dropLast(string inputStr) {
    int i = inputStr.length();
    while (inputStr[i] != ' ') {
        i--;
    }
    return inputStr.substr(0, i);
}

int getNumber(string inputStr) {
    return stoi(getLast(inputStr));
}

string getCommand(string inputStr) {
    string temp;
    for (char c : inputStr) {
        if (c == ' ') {
            return temp;
        } else {
            temp.push_back(c);
        }
    }
    return temp;
}

void executeCommand(string command) {
    string first = dropLast(command);
    string second = getLast(command);
    cout << isAnagram(first, second) << endl;
}

int main() {
    int Q;
    cin >> Q;
    vector<string> commands(Q);
    string s;
    getline(cin, s);
    if (Q == 0) {
        return 0;
    }

    for (string& c : commands) {
        getline(cin, c);
    }

    for (auto command : commands) {
        executeCommand(command);
    }

    return 0;
}
