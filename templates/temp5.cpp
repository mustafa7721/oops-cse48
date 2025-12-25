#include <iostream>
using namespace std;

template <typename T>
T amax(T arr[], int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

int main() {
    int iarr[] = {10, 20, 30, 5, 15};
    long larr[] = {1000L, 5000L, 3000L};
    double darr[] = {1.1, 5.5, 3.3, 2.2};
    float farr[] = {2.5f, 7.1f, 4.8f};

    cout << "Largest in int array: " << amax(iarr, 5) << endl;
    cout << "Largest in long array: " << amax(larr, 3) << endl;
    cout << "Largest in double array: " << amax(darr, 4) << endl;
    cout << "Largest in float array: " << amax(farr, 3) << endl;

    return 0;
}
