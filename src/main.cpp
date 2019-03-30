#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
// #include "print-vector.h"
using namespace std;

map<vector<string>, int> busesMap;

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

void executeCommand(string command) {
    vector<string> input = split(command, ' ');
    int stopsCount = stoi(input[0]);
    vector<string> stops;

    for (int i = 1; i != stopsCount + 1; i++) {
        stops.push_back(input[i]);
    }
    if (busesMap.count(stops)) {
        cout << "Already exists for " << busesMap[stops] << endl;
    } else {
        int maxCurrentBusNumber = busesMap.size();
        busesMap[stops] = maxCurrentBusNumber + 1;
        cout << "New bus " << busesMap[stops] << endl;
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
