#include <iostream>
#include <string>
#include <vector>
//#include "print-vector.h"
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

void executeCommand(string command) {
    int num;
    string temp;
    string temp1;

    if (command == "WORRY_COUNT") {
        cout << worryCount() << endl;
    } else {
        temp = command[command.length() - 1];
        temp1 = command[command.length() - 2];
        num = (int)temp[0] - 48;
        command.pop_back();
        command.pop_back();
        if (temp1 != " ") {
            command.pop_back();
            num -= num * 2;
        }
        if (command == "COME") {
            if (num > 0) {
                push(num);
            } else {
                pop(-num);
            }
        } else if (command == "WORRY") {
            markWorry(num);
        } else if (command == "QUIET") {
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