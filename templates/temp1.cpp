#include <iostream>
using namespace std;

template <typename T>
double average(T arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];  // chars are implicitly converted to int
    return sum / size;
}

int main() {
    int iarr[] = {10, 20, 30, 40, 50};
    long larr[] = {1000L, 2000L, 3000L, 4000L};
    double darr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char carr[] = {'A', 'B', 'C', 'D'};  // ASCII values

    cout << "Average of int array: " << average(iarr, 5) << endl;
    cout << "Average of long array: " << average(larr, 4) << endl;
    cout << "Average of double array: " << average(darr, 5) << endl;
    cout << "Average of char array: " << average(carr, 4) << endl;

    return 0;
}
