#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Ville {
    string nom;
    pair<double, double> position;
};

void rechercherVille(const vector<Ville>& villes, const string& nom) {
    for (const auto& ville : villes) {
        if (ville.nom == nom) {
            cout << "Position de " << nom << ": (" << ville.position.first << ", " << ville.position.second << ")" << endl;
            return;
        }
    }
    cout << "Ville non trouvée" << endl;
}

void rechercherVilleMap(const map<string, pair<double, double>>& villesMap, const string& nom) {
    auto it = villesMap.find(nom);
    if (it != villesMap.end()) {
        cout << "Position de " << nom << ": (" << it->second.first << ", " << it->second.second << ")" << endl;
    } else {
        cout << "Ville non trouvée" << endl;
    }
}

int main() {
    vector<Ville> villes = {{"Tunis", {36.8065, 10.1815}}, {"Sfax", {34.7405, 10.7603}}};
    map<string, pair<double, double>> villesMap = {{"Tunis", {36.8065, 10.1815}}, {"Sfax", {34.7405, 10.7603}}};

    rechercherVille(villes, "Tunis");
    rechercherVilleMap(villesMap, "Sfax");
    return 0;
}
