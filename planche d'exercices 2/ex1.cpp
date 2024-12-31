#include <iostream>

int main() {
    // Allocation statique pour un entier
    int staticInt = 42;
    int* ptrInt = &staticInt;
    std::cout << "Entier statique: " << *ptrInt << ", Adresse: " << ptrInt << std::endl;

    // Allocation dynamique pour un r�el
    float* dynamicFloat = new float(3.14);
    std::cout << "R�el dynamique: " << *dynamicFloat << ", Adresse: " << dynamicFloat << std::endl;

    delete dynamicFloat; // Lib�ration de la m�moire
    return 0;
}
