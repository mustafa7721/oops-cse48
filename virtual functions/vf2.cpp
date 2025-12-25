
#include <iostream>
using namespace std;

class Distance {
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0) {}
    Distance(int f, float i) : feet(f), inches(i) {}
    Distance(float total_inches) {
        feet = static_cast<int>(total_inches) / 12;
        inches = total_inches - feet * 12;
    }

    void getdist() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    void showdist() const {
        cout << feet << " feet " << inches << " inches" << endl;
    }

    friend Distance operator*(float, const Distance&);
};

Distance operator*(float m, const Distance& d) {
    float total_inches = (d.feet * 12 + d.inches) * m;
    return Distance(total_inches);
}

int main() {
    Distance dist1(5, 8.5), dist2(3, 4.0), Wdist1;

    Wdist1 = 7.5 * dist2;
    cout << "Wdist1 = 7.5 * dist2: ";
    Wdist1.showdist();

    Wdist1 = 2.0 * dist1;
    cout << "Wdist1 = 2.0 * dist1: ";
    Wdist1.showdist();

    return 0;
}
