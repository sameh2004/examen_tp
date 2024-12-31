#include <iostream>
using namespace std;

// Function to fill the array
int* remplir(int N) {
    int* t = new int[N]; // Dynamically allocate memory for the array
    for (int i = 0; i < N; i++) {
        cout << "t[" << i << "] = ";
        cin >> t[i];
    }
    return t;
}
void rechercher(int t[], int N, int v) {
    int i = 0;
    while (i < N && t[i] != v) {
        i++;
    }
    if (i == N)
        cout << "« V ne se trouve pas dans le tableau »." << endl;
    else
        cout << "V se trouve dans le tableau à la position " << i << "." << endl;
}
int main() {
    int N;
    cout << "Donner N: ";
    cin >> N;

    int* t = remplir(N);

    rechercher(t, N, 5);

    delete[] t;

    return 0;
}
