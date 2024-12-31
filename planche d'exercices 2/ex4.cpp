#include <iostream>
#include <cstdlib>

void addition(double a, double b, double& result) {
    result = a + b;
}

void soustraction(double a, double b, double& result) {
    result = a - b;
}

void multiplication(double a, double b, double& result) {
    result = a * b;
}

void division(double a, double b, double& result) {
    if (b != 0) {
        result = a / b;
    } else {
        std::cout << "Erreur: Division par zéro." << std::endl;
    }
}

int main() {
    double a, b, result;
    int choix;

    do {
        std::cout << "Choisissez une opération: 1) Addition 2) Soustraction 3) Multiplication 4) Division 5) Quitter: ";
        std::cin >> choix;

        if (choix >= 1 && choix <= 4) {
            std::cout << "Entrez deux nombres: ";
            std::cin >> a >> b;

            switch (choix) {
                case 1: addition(a, b, result); break;
                case 2: soustraction(a, b, result); break;
                case 3: multiplication(a, b, result); break;
                case 4: division(a, b, result); break;
            }
            std::cout << "Résultat: " << result << std::endl;
        }

        system("cls"); // Effacer la console

    } while (choix != 5);

    return 0;
}
