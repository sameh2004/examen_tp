#include <iostream>
#include <vector>
#include <string>

class Piece {
protected:
    std::string couleur;
    int x, y;

public:
    Piece(std::string couleur, int x, int y) : couleur(couleur), x(x), y(y) {}

    virtual std::string afficher() = 0;
};

class Pion : public Piece {
public:
    Pion(std::string couleur, int x, int y) : Piece(couleur, x, y) {}

    void deplacer() {
        if (y < 8) {
            y += 1;
        } else {
            std::cout << "Le pion ne peut pas avancer au-delà de l'échiquier." << std::endl;
        }
    }

    std::string afficher() override {
        return "Pion " + couleur + " à la position (" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};

class Roi : public Piece {
public:
    Roi(std::string couleur, int x, int y) : Piece(couleur, x, y) {}

    std::string afficher() override {
        return "Roi " + couleur + " à la position (" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};

int main() {
    std::vector<Piece*> pieces;

    pieces.push_back(new Pion("blanc", 4, 6));
    pieces.push_back(new Pion("noir", 3, 7));
    pieces.push_back(new Roi("blanc", 5, 5));

    for (Piece* piece : pieces) {
        std::cout << piece->afficher() << std::endl;
    }

    for (Piece* piece : pieces) {
        delete piece;
    }

    return 0;
}
