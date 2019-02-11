#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Reverse(vector<int>& v) {
    int j = 0;
    for (int i = v.size() - 1; i >= v.size() / 2; i--) {
        if (i == j) {
            continue;
        }

        int temp = v[j];
        v[j] = v[i];
        v[i] = temp;
        j++;
    }
}

void PrintVector(vector<int>& v) {
    for (auto x : v) {
        cout << x << ", ";
    }
    cout << endl;
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    PrintVector(numbers);
    return 0;
}