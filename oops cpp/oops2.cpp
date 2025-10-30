
// Program for a simple banking system
#include <iostream>
using namespace std;

int main() {
    float balance = 0.0;
    int choice;
    float amount;

    do {
        cout << "\n--- Banking Menu ---\n";
        cout << "1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                balance += amount;
                cout << "Deposited: " << amount << endl;
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if(amount > balance)
                    cout << "Insufficient funds!\n";
                else {
                    balance -= amount;
                    cout << "Withdrawn: " << amount << endl;
                }
                break;
            case 3:
                cout << "Current balance: " << balance << endl;
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 4);

    return 0;
}
