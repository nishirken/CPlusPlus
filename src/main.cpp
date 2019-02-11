#include <iostream>
#include <string>
#include <vector>
using namespace std;

void UpdateIfGreater(int& x, int& y) {
    if (x > y) {
        y = x;
    }
}

int main() {
    int a = 4;
    int b = 2;
    UpdateIfGreater(a, b);
    cout << b;
    return 0;
}