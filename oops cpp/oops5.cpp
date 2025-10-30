
// Program to calculate electricity bill based on units consumed
#include <iostream>
using namespace std;

int main() {
    float units, bill = 0.0;

    cout << "Enter electricity units consumed: ";
    cin >> units;

    if(units <= 100)
        bill = units * 5;       // Rs. 5 per unit for first 100 units
    else if(units <= 200)
        bill = 100*5 + (units-100)*7;  // Rs. 7 per unit for next 100 units
    else
        bill = 100*5 + 100*7 + (units-200)*10; // Rs. 10 per unit beyond 200

    float tax = bill * 0.05; // 5% tax
    float total = bill + tax;

    cout << "Electricity bill: " << bill << endl;
    cout << "Tax: " << tax << endl;
    cout << "Total amount: " << total << endl;

    return 0;
}
