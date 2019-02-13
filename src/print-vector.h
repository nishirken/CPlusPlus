#include <iostream>
#include <string>
#include <vector>

void PrintIntVector(const std::vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i != v.size() - 1) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
}

void PrintStringVector(const std::vector<string>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i != v.size() - 1) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
}

