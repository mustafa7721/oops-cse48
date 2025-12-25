
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class Money {
    long double amount;

public:
    Money() : amount(0.0) {}
    Money(long double a) : amount(a) {}

    void getMoney() {
        cin >> amount;
    }

    void showMoney() const {
        cout << fixed << setprecision(2) << "$" << amount;
    }

    Money operator+(const Money& m) const { return Money(amount + m.amount); }
    Money operator-(const Money& m) const { return Money(amount - m.amount); }
    Money operator*(const Money& m) const { return Money(amount * m.amount); }
    Money operator/(const Money& m) const { return Money(amount / m.amount); }
    Money operator%(const Money& m) const { return Money(fmod(amount, m.amount)); }
    Money operator*(long double val) const { return Money(amount * val); }
    Money operator/(long double val) const { return Money(amount / val); }

    friend Money operator*(long double val, const Money& m);
    friend Money operator/(long double val, const Money& m);
};

Money operator*(long double val, const Money& m) { return Money(val * m.amount); }
Money operator/(long double val, const Money& m) { return Money(val / m.amount); }

int main() {
    Money m1, m2;
    long double num;

    m1.getMoney();
    m2.getMoney();
    cin >> num;

    (m1 + m2).showMoney(); cout << endl;
    (m1 - m2).showMoney(); cout << endl;
    (m1 * m2).showMoney(); cout << endl;
    (m1 / m2).showMoney(); cout << endl;
    (m1 % m2).showMoney(); cout << endl;
    (m1 * num).showMoney(); cout << endl;
    (num * m2).showMoney(); cout << endl;
    (num / m2).showMoney(); cout << endl;

    return 0;
}
