
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class bMoney {
    long double amount;

public:
    bMoney() : amount(0.0) {}
    bMoney(long double a) : amount(a) {}

    void getMoney() { cin >> amount; }

    void showMoney() const { cout << fixed << setprecision(2) << "$" << amount; }

    friend bMoney round(const bMoney& m);
};

bMoney round(const bMoney& m) {
    long double intpart;
    long double frac = modfl(m.amount, &intpart);
    if (frac < 0.50) return bMoney(intpart);
    else return bMoney(intpart + 1.0);
}

int main() {
    bMoney mo1, mo2;
    int n;

    cout << "Enter number of money amounts: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        mo1.getMoney();
        mo2 = round(mo1);
        mo1.showMoney(); cout << " rounded is "; mo2.showMoney(); cout << endl;
    }

    return 0;
}
