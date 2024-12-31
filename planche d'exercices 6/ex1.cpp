#include <iostream>
#include <memory>

class Vecteur {
private:
    double x, y;

public:
    Vecteur(double x = 0, double y = 0) : x(x), y(y) {}

    void afficher() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }

    void deplacer(double dx, double dy) {
        x += dx;
        y += dy;
    }
};

class Vecteur3D : public Vecteur {
private:
    double z;

public:
    Vecteur3D(double x = 0, double y = 0, double z = 0) : Vecteur(x, y), z(z) {}

    void afficher() const {
        Vecteur::afficher();
        std::cout << ", " << z << std::endl;
    }
};

int main() {
    Vecteur v1;
    v1.afficher();
    v1.deplacer(2.5, 3.5);
    v1.afficher();

    Vecteur3D* v3D = new Vecteur3D(1, 2, 3);
    v3D->afficher();
    delete v3D;

    return 0;
}
