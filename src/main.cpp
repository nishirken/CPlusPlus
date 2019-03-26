#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
// #include "print-vector.h"
using namespace std;

map<string, string> capitals;

string changeCapital(string country, string newCapital) {
    string res;
    if (capitals.count(country)) {
        if (capitals[country] == newCapital) {
            res = "Country " + country + " hasn't changed its capital";
        } else {
            res = "Country " + country +
                " has changed its capital from " + capitals[country] + " to " + newCapital;
        }
    } else {
        res = "Introduce new country " + country + " with capital " + newCapital;
    }
    capitals[country] = newCapital;
    return res;
}

string rename(string oldCountryName, string newCountryName) {
    if (oldCountryName == newCountryName || !capitals.count(oldCountryName) || capitals.count(newCountryName)) {
        return "Incorrect rename, skip";
    } else {
        capitals[newCountryName] = capitals[oldCountryName];
        capitals.erase(oldCountryName);
        return "Country " + oldCountryName +
            " with capital " + capitals[newCountryName] + " has been renamed to " + newCountryName;
    }
}

string about(string country) {
    if (capitals.count(country)) {
        return "Country " + country + " has capital " + capitals[country];
    } else {
        return "Country " + country + " doesn't exist";
    }
}

string dump() {
    if (capitals.empty()) {
        return "There are no countries in the world";
    } else {
        string temp;
        for (auto const& x : capitals) {
            temp += (x.first + "/" + x.second + " ");
        }
        temp.pop_back();
        return temp;
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
    string cmd = getCommand(command);
    if (cmd == "CHANGE_CAPITAL") {
        string capital = getLast(command);
        string country = getLast(dropLast(command));
        cout << changeCapital(country, capital) << endl;
    } else if (cmd == "RENAME") {
        string newCountryName = getLast(command);
        string oldCountryName = getLast(dropLast(command));
        cout << rename(oldCountryName, newCountryName) << endl;
    } else if (cmd == "ABOUT") {
        string country = getLast(command);
        cout << about(country) << endl;
    } else if (cmd == "DUMP") {
        cout << dump() << endl;
    }
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
