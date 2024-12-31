#ifndef TABLEAUX_H
#define TABLEAUX_H

#include <iostream>
#include <algorithm>
#include <vector>

void afficher(const std::vector<int>& arr) {
    for (const auto& val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void trier(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
}

#endif // TABLEAUX_H
