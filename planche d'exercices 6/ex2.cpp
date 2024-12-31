#include <iostream>
#include <vector>
#include <cmath>

class Robot {
private:
    std::string nom;
    double x, y;
    double portee;
    bool estMort;

public:
    Robot(std::string nom, double x, double y, double portee)
        : nom(nom), x(x), y(y), portee(portee), estMort(false) {}

    void deplacer(double dx, double dy) {
        x += dx;
        y += dy;
    }

    void afficher() const {
        std::cout << "Nom: " << nom << ", Position: (" << x << ", " << y << "), Portée: " << portee << ", Est Mort: " << (estMort ? "Oui" : "Non") << std::endl;
    }

    double distance(const Robot& autre) const {
        return std::sqrt((x - autre.x) * (x - autre.x) + (y - autre.y) * (y - autre.y));
    }

    void tuer(Robot& autre) {
        if (!estMort && distance(autre) <= portee) {
            autre.estMort = true;
            std::cout << nom << " a tué " << autre.nom << std::endl;
        }
    }
};

class RobotChasseur : public Robot {
public:
    RobotChasseur(std::string nom, double x, double y, double portee)
        : Robot(nom, x, y, portee) {}

    void chasser(std::vector<Robot>& robots) {
        for (auto& robot : robots) {
            tuer(robot);
        }
    }
};

int main() {
    RobotChasseur optimus("Optimus", 2, 3, 25);
    optimus.deplacer(33, 19);
    optimus.afficher();

    std::vector<Robot> robots = {
        Robot("Robot1", 10, 10, 10),
        Robot("Robot2", 20, 20, 10),
        Robot("Robot3", 30, 30, 10),
        Robot("Robot4", 40, 40, 10),
        Robot("Robot5", 50, 50, 10)
    };

    optimus.chasser(robots);

    return 0;
}
