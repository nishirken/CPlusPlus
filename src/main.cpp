#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include "print-vector.h"
using namespace std;

int main() {
    int N;
    cin >> N;
    double sum = 0;
    vector<int> temperatures(N);
    string temp;
    getline(cin, temp);

    for (int i = 0; i <= N; i++) {
        temperatures[i] = (int)temp[0] - 48;
        sum += temperatures[i];
    }

    double average = sum / N;
    int counter = 0;
    vector<int> highIndexes;

    for (int i = 0; i <= N; i++) {
        if (temperatures[i] > average) {
            counter++;
            highIndexes.push_back(i);
        }
    }
//    cout << counter << endl;
//    PrintIntVector(highIndexes);

    return 0;
}