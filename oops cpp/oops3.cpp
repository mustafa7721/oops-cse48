
// Program to convert temperature between Celsius and Fahrenheit
#include <iostream>
using namespace std;

int main() {
    char scale;
    float temp, converted;

    cout << "Enter temperature (e.g., 36.5C or 98.6F): ";
    cin >> temp >> scale;

    if(scale == 'C' || scale == 'c') {
        converted = (temp * 9/5) + 32;
        cout << temp << "°C = " << converted << "°F\n";
    } else if(scale == 'F' || scale == 'f') {
        converted = (temp - 32) * 5/9;
        cout << temp << "°F = " << converted << "°C\n";
    } else {
        cout << "Invalid scale entered!\n";
    }

    return 0;
}
