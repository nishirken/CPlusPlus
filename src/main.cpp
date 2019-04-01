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

map<set<string>, string> stopsBusMap;

void executeCommand(string command) {
    vector<string> input = split(command, ' ');
    string busNumber = input[0];
    set<string> stops = set<string>(input.begin() + 1, input.end());

    if (!stopsBusMap.count(stops)) {
        stopsBusMap[stops] = to_string(stopsBusMap.size() + 1);
        cout << "New bus " + to_string(stopsBusMap.size()) << endl; 
    } else {
        cout << "Already exists for " + stopsBusMap[stops] << endl;
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
