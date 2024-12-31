#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> tab{-2, 3, -33, 7, 99, 6, 2, -39};
    std::cout << "************************\n";
    std::cout << "* 1. Afficher positif   *\n";
    std::cout << "* 2. Afficher Negatif   *\n";
    std::cout << "* 3. Superieur A       *\n";
    std::cout << "************************\n";
    std::cout << "Entrez votre choix? \n";
    int choix;
    std::cin >> choix;
    switch (choix) {
        case 1:
            std::for_each(tab.begin(), tab.end(), [](int &x) { if (x >= 0) std::cout << x << "\t"; });
            break;
        case 2:
            std::for_each(tab.begin(), tab.end(), [](int &x) { if (x < 0) std::cout << x << "\t"; });
            break;
        case 3: {
            int seuil;
            std::cout << "Donner seuil: ";
            std::cin >> seuil;
            std::for_each(tab.begin(), tab.end(), [seuil](int &x) { if (x >= seuil) std::cout << x << "\t"; });
            break;
        }
        default: break;
    }
    return 0;
}
