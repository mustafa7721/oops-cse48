
// Program to calculate grocery bill
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    string itemName[n];
    int quantity[n];
    float price[n], total = 0.0;

    for (int i = 0; i < n; i++) {
        cout << "Enter name of item " << i + 1 << ": ";
        cin >> itemName[i];
        cout << "Enter quantity: ";
        cin >> quantity[i];
        cout << "Enter price per unit: ";
        cin >> price[i];
        total += quantity[i] * price[i];
    }

    float discount = 0.0;
    if (total > 500) {  // apply discount if total > 500
        discount = total * 0.1;
    }

    cout << "\n----- Bill -----\n";
    for (int i = 0; i < n; i++) {
        cout << itemName[i] << "\t" << quantity[i] << " x " << price[i]
             << " = " << quantity[i] * price[i] << endl;
    }
    cout << "Total: " << total << endl;
    cout << "Discount: " << discount << endl;
    cout << "Amount to pay: " << total - discount << endl;

    return 0;
}
