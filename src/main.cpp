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

map<string, set<string>> synonims;

void add(const string& word1, const string& word2) {
    if (synonims.count(word1)) {
        synonims[word1].insert(word2);
    } else {
        set<string> temp;
        temp.insert(word2);
        synonims[word1] = temp;
    }
    if (synonims.count(word2)) {
        synonims[word2].insert(word1);
    } else {
        set<string> temp;
        temp.insert(word1);
        synonims[word2] = temp;
    }
}

int count(const string& word) {
    if (synonims.count(word)) {
        return synonims[word].size();
    }
    return 0;
}

string check(const string& word1, const string& word2) {
    if (
        (synonims.count(word1) && synonims[word1].count(word2)) ||
        (synonims.count(word2) && synonims[word2].count(word1))
    ) {
        return "YES";
    }
    return "NO";
}

void executeCommand(string command) {
    vector<string> input = split(command, ' ');
    string cmd = input[0];

    if (cmd == "ADD") {
        add(input[1], input[2]);
    } else if (cmd == "COUNT") {
        cout << count(input[1]) << endl;
    } else if (cmd == "CHECK") {
        cout << check(input[1], input[2]) << endl;
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
