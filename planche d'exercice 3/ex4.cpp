#include <iostream>
#include <utility>
using namespace std;

pair<int, int> minMax(int arr[], int size) {
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    return make_pair(min, max);
}

int main() {
    int arr[] = {3, 1, 4, 1, 5};
    auto result = minMax(arr, 5);
    cout << "Min: " << result.first << ", Max: " << result.second << endl;
    return 0;
}
