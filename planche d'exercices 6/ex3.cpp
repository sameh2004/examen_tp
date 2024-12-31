#include <iostream>
#include <string>

class Vehicule {
protected:
    static int numero_serie_global;
    static int numero_vehicule_global;
    int numero_serie;
    int numero_vehicule;
    int annee;
    double prix;

public:
    Vehicule(int annee, double prix) : annee(annee), prix(prix) {
        numero_vehicule = numero_vehicule_global;
        numero_serie = numero_serie_global;
        numero_vehicule_global++;
        if (numero_vehicule_global > 10000) {
            numero_vehicule_global = 1;
            numero_serie_global++;
        }
    }

    virtual std::string accelerer() = 0;

    std::string afficher() {
        return std::to_string(numero_serie) + " " + std::to_string(numero_vehicule) + ", Année: " + std::to_string(annee) + ", Prix: " + std::to_string(prix);
    }
};

int Vehicule::numero_serie_global = 1;
int Vehicule::numero_vehicule_global = 1;

class Voiture : public Vehicule {
private:
    int nombre_places;

public:
    Voiture(int annee, double prix, int nombre_places) : Vehicule(annee, prix), nombre_places(nombre_places) {}

    std::string accelerer() override {
        return "Je peux atteindre 200km/h";
    }
};

class Camion : public Vehicule {
private:
    double charge_maximale;

public:
    Camion(int annee, double prix, double charge_maximale) : Vehicule(annee, prix), charge_maximale(charge_maximale) {}

    std::string accelerer() override {
        return "Je peux atteindre 120km/h";
    }
};

int main() {
    Voiture voiture1(2020, 15000, 5);
    Camion camion1(2019, 30000, 1000);

    std::cout << voiture1.afficher() << std::endl;
    std::cout << voiture1.accelerer() << std::endl;

    std::cout << camion1.afficher() << std::endl;
    std::cout << camion1.accelerer() << std::endl;

    return 0;
}
