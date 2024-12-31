#include <iostream>
#include <cmath>

class Point {
private:
    float x, y;

public:
    Point(float x = 0, float y = 0) : x(x), y(y) {}
    Point(const Point& p) : x(p.x), y(p.y) {}

    void affiche() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }

    friend bool comparer(const Point& p1, const Point& p2) {
        return (p1.x == p2.x && p1.y == p2.y);
    }

    friend float distance(const Point& p1, const Point& p2) {
        return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }

    friend Point milieu(const Point& p1, const Point& p2) {
        return Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
    }
};

int main() {
    Point p1(1, 2);
    Point p2(3, 4);

    p1.affiche();
    p2.affiche();

    bool identiques = comparer(p1, p2);
    std::cout << "Les points sont identiques: " << (identiques ? "Oui" : "Non") << std::endl;

    float dist = distance(p1, p2);
    std::cout << "Distance entre p1 et p2: " << dist << std::endl;

    Point m = milieu(p1, p2);
    std::cout << "Point milieu: ";
    m.affiche();

    return 0;
}
