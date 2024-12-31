#include <iostream>
#include <vector>

template <typename T>
void echanger(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void trier(std::vector<T> &tab) {
    for (size_t i = 0; i < tab.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < tab.size(); ++j) {
            if (tab[j] < tab[minIndex]) {
                minIndex = j;
            }
        }
        echanger(tab[i], tab[minIndex]);
    }
}
