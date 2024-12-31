#include <iostream>

int main() {
    // Allocation statique pour un entier
    int staticInt = 42;
    int* ptrInt = &staticInt;
    std::cout << "Entier statique: " << *ptrInt << ", Adresse: " << ptrInt << std::endl;

    // Allocation dynamique pour un réel
    float* dynamicFloat = new float(3.14);
    std::cout << "Réel dynamique: " << *dynamicFloat << ", Adresse: " << dynamicFloat << std::endl;

    delete dynamicFloat; // Libération de la mémoire
    return 0;
}
