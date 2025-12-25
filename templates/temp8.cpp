#include <iostream>
using namespace std;

class OutOfBounds {
    int index;
public:
    OutOfBounds(int i) : index(i) {}
    int getIndex() const { return index; }
};

class SafeArray {
    int arr[10];
public:
    int& operator[](int index) {
        if (index < 0 || index >= 10)
            throw OutOfBounds(index);
        return arr[index];
    }
};

int main() {
    SafeArray sa;

    try {
        for (int i = 0; i <= 10; i++) {
            sa[i] = i * 10;
            cout << "sa[" << i << "] = " << sa[i] << endl;
        }
    }
    catch (OutOfBounds &e) {
        cout << "Error: index " << e.getIndex() << " is out of bounds." << endl;
    }

    return 0;
}
