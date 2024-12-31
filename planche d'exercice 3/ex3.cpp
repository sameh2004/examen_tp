#include <iostream>
#include <vector>
using namespace std;

int produitScalaire(const vector<int>& U, const vector<int>& V) {
    int resulta = 0;
    for (size_t i = 0; i < U.size(); i++) {
        resulta += U[i] * V[i];
    }
    return resulta;
}

int main() {
    vector<int> U = {1, 2, 3};
    vector<int> V = {4, 5, 6};
    cout << "Produit scalaire: " << produitScalaire(U, V) << endl;
    return 0;
}
