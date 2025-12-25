#include <iostream>
using namespace std;

class Array {
private:
    int* ptr;
    int size;

public:
    Array(int s) : size(s) {
        ptr = new int[s];
    }

    ~Array() {
        delete[] ptr;
    }

    Array(const Array& a) {  // Copy constructor
        size = a.size;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
            ptr[i] = a.ptr[i];
    }

    Array& operator=(const Array& a) {  // Assignment operator
        if (this == &a) return *this;

        if (size != a.size) {  // Resize if sizes differ
            delete[] ptr;
            size = a.size;
            ptr = new int[size];
        }

        for (int i = 0; i < size; i++)
            ptr[i] = a.ptr[i];

        return *this;
    }

    int& operator[](int j) {
        return ptr[j];
    }
};

int main() {
    const int ASIZE = 10;
    Array arr1(ASIZE);

    for (int j = 0; j < ASIZE; j++)
        arr1[j] = j * j;

    for (int j = 0; j < ASIZE; j++)
        cout << arr1[j] << " ";
    cout << endl;

    Array arr2(arr1);  // Copy constructor
    Array arr3(5);     // Different size initially
    arr3 = arr1;       // Assignment operator

    cout << "arr2 contents: ";
    for (int j = 0; j < ASIZE; j++)
        cout << arr2[j] << " ";
    cout << endl;

    cout << "arr3 contents: ";
    for (int j = 0; j < ASIZE; j++)
        cout << arr3[j] << " ";
    cout << endl;

    return 0;
}
