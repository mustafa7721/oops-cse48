
// Program to calculate BMI
#include <iostream>
using namespace std;

int main() {
    float weight, height, bmi;

    cout << "Enter weight (kg): ";
    cin >> weight;
    cout << "Enter height (m): ";
    cin >> height;

    bmi = weight / (height * height);

    cout << "Your BMI: " << bmi << endl;

    if(bmi < 18.5)
        cout << "Category: Underweight\n";
    else if(bmi < 24.9)
        cout << "Category: Normal weight\n";
    else if(bmi < 29.9)
        cout << "Category: Overweight\n";
    else
        cout << "Category: Obese\n";

    return 0;
}

