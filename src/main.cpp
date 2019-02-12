#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include "print-vector.h"
using namespace std;

int main() {
    int N;
    string str;

    cin >> N;
    double sum = 0;

    vector<int> temperatures(N);
    vector<string> rawTemp(N);
    string temp;
    string::size_type sz;
    cin >> str;

    for (auto s : str) {
        if (s != ' ') {
            temp = "";
            temp.push_back(s);
            cout << temp << endl;
            rawTemp.push_back(temp);
        }
    }

    for (int i = 0; i <= N; i++) {
        temperatures[i] = stoi(rawTemp[i], &sz);
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
    cout << counter << endl;
    PrintIntVector(highIndexes);

    return 0;
}