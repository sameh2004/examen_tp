#include <iostream>
#include <string>

class Personne {
protected:
    std::string nom;
    int age;
    char sexe;

public:
    Personne(std::string nom, int age, char sexe) : nom(nom), age(age), sexe(sexe) {}

    std::string getNom() const {
        return nom;
    }

    void setNom(const std::string& nom) {
        this->nom = nom;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        this->age = age;
    }

    char getSexe() const {
        return sexe;
    }

    void setSexe(char sexe) {
        this->sexe = sexe;
    }

    std::string getPersonne() const {
        return "Nom: " + nom + ", Age: " + std::to_string(age) + ", Sexe: " + sexe;
    }
};

class Enseignant : public Personne {
private:
    std::string charge;

public:
    Enseignant(std::string nom, int age, char sexe, std::string charge)
        : Personne(nom, age, sexe), charge(charge) {}

    std::string getCharge() const {
        return charge;
    }

    void setCharge(const std::string& charge) {
        this->charge = charge;
    }

    std::string getPersonne() const override {
        return Personne::getPersonne() + ", Charge: " + charge;
    }
};

class Etudiant : public Personne {
private:
    std::string filiere;

public:
    Etudiant(std::string nom, int age, char sexe, std::string filiere)
        : Personne(nom, age, sexe), filiere(filiere) {}

    std::string getFiliere() const {
        return filiere;
    }

    void setFiliere(const std::string& filiere) {
        this->filiere = filiere;
    }

    std::string getPersonne() const override {
        return Personne::getPersonne() + ", Filière: " + filiere;
    }
};

class Contractuel : public Enseignant, public Etudiant {
public:
    Contractuel(std::string nom, int age, char sexe, std::string charge, std::string filiere)
        : Personne(nom, age, sexe), Enseignant(nom, age, sexe, charge), Etudiant(nom, age, sexe, filiere) {}

    std::string getPersonne() const override {
        return Enseignant::getPersonne() + ", Filière: " + Etudiant::getFiliere();
    }
};

int main() {
    Enseignant enseignant("Alice", 35, 'F', "Mathématiques");
    Etudiant etudiant("Bob", 20, 'M', "Informatique");
    Contractuel contractuel("Charlie", 30, 'M', "Physique", "Chimie");

    std::cout << enseignant.getPersonne() << std::endl;
    std::cout << etudiant.getPersonne() << std::endl;
    std::cout << contractuel.getPersonne() << std::endl;

    return 0;
}
