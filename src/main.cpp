#include <iostream>
#include <string>
using namespace std;

int Factorial(int x) {
    if (x <= 1) {
        return 1;
    }

    return Factorial(x - 1) * x;
}

int main() {
    int x;
    cin >> x;
    cout << Factorial(x);
    return 0;
}