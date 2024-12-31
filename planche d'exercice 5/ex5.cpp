#include <iostream>
#include <cmath>

class Point {
private:
    double x, y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    void afficher() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    void translater(double dx, double dy) {
        x += dx;
        y += dy;
    }

    double distance(const Point& p) const {
        return std::sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
};

class Cercle {
private:
    double rayon;
    Point centre;

public:
    Cercle(double rayon = 1.0, const Point& centre = Point()) : rayon(rayon), centre(centre) {}
    Cercle(double rayon = 1.0, double x = 0, double y = 0) : rayon(rayon), centre(Point(x, y)) {}

    void afficher() const {
        std::cout << "Cercle de rayon: " << rayon << " et centre: ";
        centre.afficher();
    }

    double getRayon() const {
        return rayon;
    }

    void setRayon(double r) {
        rayon = r;
    }

    Point getCentre() const {
        return centre;
    }

    void translater(double dx, double dy) {
        centre.translater(dx, dy);
    }

    double surface() const {
        return M_PI * rayon * rayon;
    }

    double perimetre() const {
        return 2 * M_PI * rayon;
    }

    bool estEgal(const Cercle& c) const {
        return (rayon == c.rayon && centre.getX() == c.centre.getX() && centre.getY() == c.centre.getY());
    }

    bool contient(const Point& p) const {
        return centre.distance(p) <= rayon;
    }
};

int main() {
    Cercle c1(1, Point(10, 10));
    c1.afficher();

    std::cout << "Périmètre: " << c1.perimetre() << std::endl;
    std::cout << "Surface: " << c1.surface() << std::endl;

    c1.setRayon(c1.getRayon() * 2);
    std::cout << "Après doublement du rayon:" << std::endl;
    c1.afficher();
    std::cout << "Périmètre: " << c1.perimetre() << std::endl;
    std::cout << "Surface: " << c1.surface() << std::endl;

    c1.translater(-10, -10);
    std::cout << "Après translation du centre à l'origine:" << std::endl;
    c1.afficher();

    Point p1(1, 1);
    Point p2(3, 3);
    std::cout << "Point (1,1) est à l'intérieur du cercle: " << (c1.contient(p1) ? "Oui" : "Non") << std::endl;
    std::cout << "Point (3,3) est à l'extérieur du cercle: " << (c1.contient(p2) ? "Non" : "Oui") << std::endl;

    Cercle c2(2, Point(0, 0));
    std::cout << "Cercle c1 est égal à c2: " << (c1.estEgal(c2) ? "Oui" : "Non") << std::endl;

    return 0;
}
