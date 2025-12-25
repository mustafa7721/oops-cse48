#include <iostream>
using namespace std;

template <typename T>
void swaps(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int i1 = 10, i2 = 20;
    cout << "Before swap: i1 = " << i1 << ", i2 = " << i2 << endl;
    swaps(i1, i2);
    cout << "After swap: i1 = " << i1 << ", i2 = " << i2 << endl;

    double d1 = 3.14, d2 = 2.71;
    cout << "\nBefore swap: d1 = " << d1 << ", d2 = " << d2 << endl;
    swaps(d1, d2);
    cout << "After swap: d1 = " << d1 << ", d2 = " << d2 << endl;

    char c1 = 'A', c2 = 'Z';
    cout << "\nBefore swap: c1 = " << c1 << ", c2 = " << c2 << endl;
    swaps(c1, c2);
    cout << "After swap: c1 = " << c1 << ", c2 = " << c2 << endl;

    float f1 = 1.1f, f2 = 2.2f;
    cout << "\nBefore swap: f1 = " << f1 << ", f2 = " << f2 << endl;
    swaps(f1, f2);
    cout << "After swap: f1 = " << f1 << ", f2 = " << f2 << endl;

    return 0;
}
