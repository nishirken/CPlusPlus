#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string xs) {
    char reversed[xs.length()];
    int j = 0;
    for (int i = xs.length() - 1; i >= 0; i--) {
        reversed[j] = xs[i];
        j++;
    }
    return reversed == xs;
}

void printBool(bool x) {
    if (x) {
        cout << "true";
    } else {
        cout << "false";
    }
}

int main() {
    string xs;
    cin >> xs;
    printBool(IsPalindrom(xs));
    return 0;
}