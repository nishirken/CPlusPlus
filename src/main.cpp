#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// #include "print-vector.h"
using namespace std;

const int quietHuman = 1;
const int worryHuman = 0;
vector<int> queue;

void push(int elementsCount) {
    while(elementsCount--) {
        queue.push_back(quietHuman);
    }
}

void pop(int elementsCount) {
    if (elementsCount > queue.size()) {
        elementsCount = queue.size();
    }

    while(elementsCount--) {
        queue.pop_back();
    }
}

void markWorry(int index) {
    for (int i = 0; i <= queue.size(); i++) {
        if (i == index) {
            queue[i] = worryHuman;
        }
    }
}

void markQuiet(int index) {
    for (int i = 0; i <= queue.size(); i++) {
        if (i == index) {
            queue[i] = quietHuman;
        }
    }
}

int worryCount() {
    int temp = 0;
    for (int human : queue) {
        if (human == worryHuman) {
            temp++;
        }
    }
    return temp;
}

int getNumber(string inputStr) {
    string temp;
    int i = inputStr.length() - 1;

    for (i; inputStr[i] != ' '; i--) {
        temp.push_back(inputStr[i]);
    }
    reverse(temp.begin(), temp.end());

    return stoi(temp);
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
    int num;
    string cmd;

    if (command == "WORRY_COUNT") {
        cout << worryCount() << endl;
    } else {
        num = getNumber(command);
        cmd = getCommand(command);

        if (cmd == "COME") {
            if (num > 0) {
                push(num);
            } else {
                pop(-num);
            }
        } else if (cmd == "WORRY") {
            markWorry(num);
        } else if (cmd == "QUIET") {
            markQuiet(num);
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
