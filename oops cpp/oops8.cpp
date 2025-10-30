
// Program to convert currencies
#include <iostream>
using namespace std;

int main() {
    double amount, converted;
    int choice;

    cout << "Select conversion:\n";
    cout << "1. USD to INR\n2. EUR to USD\n3. INR to USD\n";
    cin >> choice;
    cout << "Enter amount: ";
    cin >> amount;

    switch(choice) {
        case 1:
            converted = amount * 83.5; // Example rate
            cout << amount << " USD = " << converted << " INR\n";
            break;
        case 2:
            converted = amount * 1.1; // Example rate
            cout << amount << " EUR = " << converted << " USD\n";
            break;
        case 3:
            converted = amount / 83.5; // Example rate
            cout << amount << " INR = " << converted << " USD\n";
            break;
        default:
            cout << "Invalid choice!\n";
    }

    return 0;
}
