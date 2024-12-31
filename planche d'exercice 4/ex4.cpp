#include <iostream>

struct Produit {
    std::string type;
    double prixHT;
    bool solde;
};

double calculerPrix(const Produit &p) {
    double taux = (p.type == "luxe") ? 0.25 : 0.19;
    double prixTTC = p.prixHT * (1 + taux);
    if (p.solde) {
        prixTTC *= 0.8;
    }
    return prixTTC;
}

int main() {
    Produit p1{"normal", 100.0, false};
    Produit p2{"luxe", 200.0, true};
    std::cout << "Prix produit 1: " << calculerPrix(p1) << "\n";
    std::cout << "Prix produit 2: " << calculerPrix(p2) << "\n";
    return 0;
}
