#include <iostream>

void incrementer(int* a) {
    (*a)++;
}

void permuter(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int val = 10;
    incrementer(&val);
    std::cout << "Valeur après incrémentation: " << val << std::endl;

    int a = 5, b = 10;
    permuter(&a, &b);
    std::cout << "Après permutation: a = " << a << ", b = " << b << std::endl;

    return 0;
}
