#include <iostream>
#include <cmath>

class Complexe {
private:
    double Re;
    double Img;

public:
    Complexe(double re = 0.0, double img = 0.0) : Re(re), Img(img) {}

    void afficher() const {
        std::cout << Re << (Img >= 0 ? "+" : "") << Img << "i" << std::endl;
    }

    double module() const {
        return std::sqrt(Re * Re + Img * Img);
    }

    Complexe conjugue() const {
        return Complexe(Re, -Img);
    }

    Complexe operator+(const Complexe& c) const {
        return Complexe(Re + c.Re, Img + c.Img);
    }

    Complexe operator+(double d) const {
        return Complexe(Re + d, Img);
    }

    friend Complexe operator+(double d, const Complexe& c) {
        return Complexe(d + c.Re, c.Img);
    }

    Complexe operator-(const Complexe& c) const {
        return Complexe(Re - c.Re, Img - c.Img);
    }

    Complexe operator*(const Complexe& c) const {
        return Complexe(Re * c.Re - Img * c.Img, Re * c.Img + Img * c.Re);
    }

    Complexe operator*(double d) const {
        return Complexe(Re * d, Img * d);
    }

    friend Complexe operator*(double d, const Complexe& c) {
        return Complexe(d * c.Re, d * c.Img);
    }
};

int main() {
    Complexe c1(3, 4);
    Complexe c2(1, 2);

    std::cout << "c1: ";
    c1.afficher();
    std::cout << "c2: ";
    c2.afficher();

    Complexe c3 = c1 + c2;
    std::cout << "c1 + c2: ";
    c3.afficher();

    Complexe c4 = c1 - c2;
    std::cout << "c1 - c2: ";
    c4.afficher();

    Complexe c5 = c1 * c2;
    std::cout << "c1 * c2: ";
    c5.afficher();

    Complexe c6 = c1 + 5.0;
    std::cout << "c1 + 5: ";
    c6.afficher();

    Complexe c7 = 5.0 + c1;
    std::cout << "5 + c1: ";
    c7.afficher();

    Complexe c8 = c1 * 2.0;
    std::cout << "c1 * 2: ";
    c8.afficher();

    Complexe c9 = 2.0 * c1;
    std::cout << "2 * c1: ";
    c9.afficher();

    std::cout << "Module de c1: " << c1.module() << std::endl;
    std::cout << "Conjugué de c1: ";
    c1.conjugue().afficher();

    return 0;
}
