#include <iostream>
#include <cmath>

class Vecteur3D {
private:
    float x, y, z;

public:
    Vecteur3D(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    void afficher() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }

    Vecteur3D somme(const Vecteur3D& v) const {
        return Vecteur3D(x + v.x, y + v.y, z + v.z);
    }

    float produitScalaire(const Vecteur3D& v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    bool coince(const Vecteur3D& v) const {
        return (x == v.x && y == v.y && z == v.z);
    }

    float norme() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vecteur3D normax(const Vecteur3D& v) const {
        return (norme() > v.norme()) ? *this : v;
    }

    Vecteur3D* normaxAdresse(Vecteur3D* v) {
        return (norme() > v->norme()) ? this : v;
    }

    Vecteur3D& normaxReference(Vecteur3D& v) {
        return (norme() > v.norme()) ? *this : v;
    }
};

int main() {
    Vecteur3D v1(1, 2, 3);
    Vecteur3D v2(4, 5, 6);

    v1.afficher();
    v2.afficher();

    Vecteur3D v3 = v1.somme(v2);
    v3.afficher();

    float produit = v1.produitScalaire(v2);
    std::cout << "Produit scalaire: " << produit << std::endl;

    bool coincide = v1.coince(v2);
    std::cout << "Les vecteurs coïncident: " << (coincide ? "Oui" : "Non") << std::endl;

    float normeV1 = v1.norme();
    std::cout << "Norme de v1: " << normeV1 << std::endl;

    Vecteur3D vMax = v1.normax(v2);
    std::cout << "Vecteur avec la plus grande norme (par valeur): ";
    vMax.afficher();

    Vecteur3D* vMaxAdresse = v1.normaxAdresse(&v2);
    std::cout << "Vecteur avec la plus grande norme (par adresse): ";
    vMaxAdresse->afficher();

    Vecteur3D& vMaxReference = v1.normaxReference(v2);
    std::cout << "Vecteur avec la plus grande norme (par référence): ";
    vMaxReference.afficher();

    return 0;
}
