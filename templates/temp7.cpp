#include <iostream>
using namespace std;

template <typename T>
class frac {
    T num;
    T den;

    void simplify() {
        T a = num, b = den;
        while (b != 0) {
            T temp = b;
            b = a % b;
            a = temp;
        }
        num /= a;
        den /= a;
    }

public:
    frac(T n = 0, T d = 1) : num(n), den(d) {
        if (den == 0) {
            cout << "Error: denominator cannot be zero.\n";
            exit(1);
        }
        simplify();
    }

    frac operator+(const frac &f) const {
        return frac(num * f.den + f.num * den, den * f.den);
    }

    frac operator-(const frac &f) const {
        return frac(num * f.den - f.num * den, den * f.den);
    }

    frac operator*(const frac &f) const {
        return frac(num * f.num, den * f.den);
    }

    frac operator/(const frac &f) const {
        return frac(num * f.den, den * f.num);
    }

    void display() const {
        cout << int(num) << "/" << int(den) << endl;
    }
};

int main() {
    int na, da, nb, db;
    cin >> na >> da;
    cin >> nb >> db;

    frac<char> f1(na, da);
    frac<char> f2(nb, db);

    (f1 + f2).display();
    (f1 - f2).display();
    (f1 * f2).display();
    (f1 / f2).display();

    return 0;
}
