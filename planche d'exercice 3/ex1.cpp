#include <iostream>
#include <vector>
using namespace std;
vector<int> creerTableau(int taille) {
    return vector<int>(taille);
}
void remplirTableau(vector<int>& tableau) {
    cout << "Entrez " << tableau.size() << " valeurs entières :" << endl;
    for (int i = 0; i < tableau.size(); ++i) {
        cin >> tableau[i];
    }
}
int compterValeursPositives(const vector<int>& tableau) {
    int compteur = 0;
    for (int valeur : tableau) {
        if (valeur > 0) {
            ++compteur;
        }
    }
    return compteur;
}
int main() {
    int t;
    cout << "Entrez la taille du tableau : ";
    cin >> t;
    if (t <= 0) {
        cout << "La taille doit être un entier positif." << endl;
        return 1;
    }
    vector<int> tableau = creerTableau(t);
    remplirTableau(tableau);
    int nbPositifs = compterValeursPositives(tableau);
    cout << "Nombre de valeurs positives : " << nbPositifs << endl;
    return 0;
}

