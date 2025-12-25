#include <iostream>
using namespace std;

template <typename T, int SIZE>
class SafeArray {
    T arr[SIZE];

public:
    T& operator[](int index) {
        if (index < 0 || index >= SIZE) {
            cout << "Error: index " << index << " out of bounds.\n";
            exit(1);
        }
        return arr[index];
    }

    int size() const {
        return SIZE;
    }
};

int main() {
    SafeArray<int, 5> intArray;
    SafeArray<double, 4> doubleArray;

    // Store values in int array
    for (int i = 0; i < intArray.size(); i++)
        intArray[i] = i * 10;

    // Store values in double array
    for (int i = 0; i < doubleArray.size(); i++)
        doubleArray[i] = i * 1.5;

    // Display int array
    cout << "Int array: ";
    for (int i = 0; i < intArray.size(); i++)
        cout << intArray[i] << " ";
    cout << endl;

    // Display double array
    cout << "Double array: ";
    for (int i = 0; i < doubleArray.size(); i++)
        cout << doubleArray[i] << " ";
    cout << endl;

    return 0;
}
