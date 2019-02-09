#include <iostream>
#include <string>
using namespace std;

void printSmallestString() {
    string x = "";
    string y = "";
    string z = "";
    cin >> x >> y >> z;

    if (x < y) {
        if (x < z) {
            cout << x;
        } else {
            cout << z;
        }
    } else {
        if (y < z) {
            cout << y;
        } else {
            cout << z;
        }
    }

int main() {
    printSmallestString();
    return 0;
}