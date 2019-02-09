#include <iostream>
using namespace std;

void printStdinSum() {
    int x = 0;
    int y = 0;
    cin >> x >> y;
    cout << (x + y) << "\n";
}

int main() {
    printStdinSum();
    return 0;
}