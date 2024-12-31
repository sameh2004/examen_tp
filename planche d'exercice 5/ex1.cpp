#include <iostream>
#include <string>

class Etudiant {
private:
    static int compteur;
    int matricule;
    std::string nom;
    int nbrNotes;
    float* tabNotes;

public:
    Etudiant() : matricule(++compteur), nom(""), nbrNotes(0), tabNotes(nullptr) {}

    Etudiant(const std::string& nom, int nbrNotes) : matricule(++compteur), nom(nom), nbrNotes(nbrNotes) {
        tabNotes = new float[nbrNotes];
    }

    ~Etudiant() {
        delete[] tabNotes;
    }

    Etudiant(const Etudiant& other) : matricule(other.matricule), nom(other.nom), nbrNotes(other.nbrNotes) {
        tabNotes = new float[nbrNotes];
        for (int i = 0; i < nbrNotes; ++i) {
            tabNotes[i] = other.tabNotes[i];
        }
    }

    void setNom(const std::string& nom) {
        this->nom = nom;
    }

    std::string getNom() const {
        return nom;
    }

    void saisie() {
        std::cout << "Saisir le nombre de notes: ";
        std::cin >> nbrNotes;
        tabNotes = new float[nbrNotes];
        for (int i = 0; i < nbrNotes; ++i) {
            std::cout << "Saisir la note " << (i + 1) << ": ";
            std::cin >> tabNotes[i];
        }
    }

    void affichage() const {
        std::cout << "Matricule: " << matricule << "\nNom: " << nom << "\nNotes: ";
        for (int i = 0; i < nbrNotes; ++i) {
            std::cout << tabNotes[i] << " ";
        }
        std::cout << "\n";
    }

    float moyenne() const {
        float somme = 0;
        for (int i = 0; i < nbrNotes; ++i) {
            somme += tabNotes[i];
        }
        return nbrNotes > 0 ? somme / nbrNotes : 0;
    }

    bool admis() const {
        return moyenne() >= 10;
    }

    static bool comparer(const Etudiant& e1, const Etudiant& e2) {
        return e1.moyenne() == e2.moyenne();
    }
};

int Etudiant::compteur = 0;

int main() {
    Etudiant e1("Alice", 3);
    e1.saisie();
    e1.affichage();
    std::cout << "Admis: " << (e1.admis() ? "Oui" : "Non") << "\n";

    Etudiant e2("Bob", 3);
    e2.saisie();
    e2.affichage();
    std::cout << "Admis: " << (e2.admis() ? "Oui" : "Non") << "\n";

    std::cout << "Comparaison des moyennes: " << (Etudiant::comparer(e1, e2) ? "Egal" : "Différent") << "\n";

    return 0;
}
