#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
// #include "print-vector.h"
using namespace std;

const vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int currentMonth = 0;
map<int, vector<string>> dayTasks;

void add(int day, string task) {
    if (dayTasks.count(day)) {
        dayTasks[day].push_back(task);
    } else {
        dayTasks.insert(pair<int, vector<string>>(day, {task}));
    }
}

string getTasks(int day) {
    vector<string> tasksInDay = dayTasks[day];
    string res;
    for (string task : tasksInDay) {
        res += task + " ";
    }
    
    if (res.length() > 0) {
        res.pop_back();
    }

    return to_string(tasksInDay.size()) + " " + res;
}

void next() {
    int daysInPrevMonth = daysInMonths[currentMonth];

    if (currentMonth == 11) {
        currentMonth = 0;
    } else {
        currentMonth++;
    }
    int daysInCurrentMonth = daysInMonths[currentMonth];

    if (daysInCurrentMonth < daysInPrevMonth) {
        for (int i = daysInCurrentMonth + 1; i <= daysInPrevMonth; i++) {
            if (dayTasks.count(i)) {
                if (!dayTasks.count(daysInCurrentMonth)) {
                    dayTasks[daysInCurrentMonth] = dayTasks[i];
                    dayTasks.erase(i);
                    continue;
                }

                dayTasks[daysInCurrentMonth].insert(
                    dayTasks[daysInCurrentMonth].end(),
                    dayTasks[i].begin(),
                    dayTasks[i].end()
                );
                dayTasks.erase(i);
            }
        }
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
    string cmd;
    string task;
    vector<string> tasks;
    int number;

    if (command == "NEXT") {
        next();
    } else {
        cmd = getCommand(command);
        if (cmd == "DUMP") {
            cout << getTasks(getNumber(command)) << endl;
        } else if (cmd == "ADD") {
            add(getNumber(dropLast(command)), getLast(command));
        }
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
