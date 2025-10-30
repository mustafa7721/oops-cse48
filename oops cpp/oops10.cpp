
// Program to simulate phone recharge
#include <iostream>
using namespace std;

int main() {
    float balance, recharge;

    cout << "Enter current balance: $";
    cin >> balance;
    cout << "Enter recharge amount: $";
    cin >> recharge;

    balance += recharge;

    cout << "Recharge successful!\n";
    cout << "New balance: $" << balance << endl;

    if(recharge >= 50)
        cout << "Bonus: 500MB data added!\n";

    return 0;
}
