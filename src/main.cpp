#include <iostream>
#include <string>
#include <vector>
#include "print-vector.h"
using namespace std;

int main() {
    int N;
    cin >> N;

    int sum = 0;
    string str;
    vector<int> temperatures(N);

    for (int& t : temperatures) {
        cin >> t;
        sum += t;
    }

    int average = sum / N;
    vector<int> highIndexes;

    for (int i = 0; i <= N; i++) {
        if (temperatures[i] > average) {
            highIndexes.push_back(i);
        }
    }
    cout << highIndexes.size() << endl;
    PrintIntVector(highIndexes);

    return 0;
}