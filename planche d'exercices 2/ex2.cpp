#include <iostream>

bool testEgaliteValeur(int a, int b) {
    return a == b;
}

bool testEgaliteAdresse(int* a, int* b) {
    return *a == *b;
}

bool testEgaliteReference(int& a, int& b) {
    return a == b;
}

int main() {
    int x = 5, y = 5;

    std::cout << "Passage par valeur: " << testEgaliteValeur(x, y) << std::endl;
    std::cout << "Passage par adresse: " << testEgaliteAdresse(&x, &y) << std::endl;
    std::cout << "Passage par référence: " << testEgaliteReference(x, y) << std::endl;

    return 0;
}
