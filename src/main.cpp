#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
// #include "print-vector.h"
using namespace std;

map<string, vector<string>> busesMap;
map<string, vector<string>> stopsMap;

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

void newBus(const string& bus, const vector<string>& stops) {
    busesMap[bus] = stops;
    for (const auto& stop : stops) {
        if (stopsMap.count(stop)) {
            for (auto const& b : stopsMap[stop]) {
                if (b == bus) {
                    return;
                }
            }
            stopsMap[stop].push_back(bus);
        } else {
            stopsMap[stop] = {bus};
        }
    }
}

string busesForStop(const string& stop) {
    if (!stopsMap.count(stop)) {
        return "No stop";
    }

    string temp;
    for (auto const& bus : stopsMap[stop]) {
            temp += (bus + " ");
        }
    temp.pop_back();
    return temp;
}

string stopsForBus(const string& bus) {
    if (!busesMap.count(bus)) {
        return "No bus";
    } else {
        string temp;
        for (auto const& stop : busesMap[bus]) {
            string stopStr = "Stop " + stop + ": ";
            int i = 0;
            for (auto const& busForStop : stopsMap[stop]) {
                if (busForStop != bus) {
                    i++;
                    stopStr += (busForStop + " ");
                }
            }
            if (i == 0) {
                stopStr += "no interchange";
            } else {
                stopStr.pop_back();
            }
            temp += (stopStr + "\n");
        }
        temp.pop_back();
        return temp;
    }
}

string allBuses() {
    if (busesMap.empty()) {
        return "No buses";
    } else {
        string temp;
        for (auto const& bus : busesMap) {
            temp += ("Bus " + bus.first + ": ");
            for (auto const& stop : bus.second) {
                temp += (stop + " ");
            }
            temp[temp.length() - 1] = '\n';
        }
        temp.pop_back();
        return temp;
    }
}

void executeCommand(string command) {
    vector<string> input = split(command, ' ');
    string cmd = input[0];
    if (cmd == "NEW_BUS") {
        int stopsCount = stoi(input[2]);
        vector<string> stops;
        for (int i = 0; i != stopsCount; i++) {
            stops.push_back(input[i + 3]);
        }
        newBus(input[1], stops);
    } else if (cmd == "BUSES_FOR_STOP") {
        cout << busesForStop(input[1]) << endl;
    } else if (cmd == "STOPS_FOR_BUS") {
        cout << stopsForBus(input[1]) << endl;
    } else if (cmd == "ALL_BUSES") {
        cout << allBuses() << endl;
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
