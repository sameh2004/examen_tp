#include <iostream>
#include <cstdlib>
#include <ctime>

float genererReelAleatoire(float min, float max) {
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

int genererEntierAleatoire(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    std::cout << "Nombres réels aléatoires: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << genererReel
