#include <iostream>
#include "tableaux.h"
#include <vector>

int main() {
    std::vector<int> arr = {5, 3, 8, 1, 2};

    std::cout << "Tableau avant tri: ";
    afficher(arr);

    trier(arr);

    std::cout << "Tableau après tri: ";
    afficher(arr);

    return 0;
}
