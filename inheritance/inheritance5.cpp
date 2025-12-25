
#include <iostream>
#include <string>
using namespace std;

enum period { hourly, weekly, monthly };

class employee {
protected:
    int emp_number;

public:
    void getdata() {
        cout << "Enter employee number: ";
        cin >> emp_number;
    }

    void putdata() const {
        cout << "Employee number: " << emp_number << endl;
    }
};

class employee2 : public employee {
protected:
    double compensation;
    period pay_period;

public:
    void getdata() {
        employee::getdata();
        cout << "Enter compensation amount: ";
        cin >> compensation;
        char ch;
        cout << "Enter pay period (h = hourly, w = weekly, m = monthly): ";
        cin >> ch;
        if (ch == 'h' || ch == 'H')
            pay_period = hourly;
        else if (ch == 'w' || ch == 'W')
            pay_period = weekly;
        else
            pay_period = monthly;
    }

    void putdata() const {
        employee::putdata();
        cout << "Compensation: " << compensation << endl;
        cout << "Pay period: ";
        if (pay_period == hourly) cout << "Hourly";
        else if (pay_period == weekly) cout << "Weekly";
        else cout << "Monthly";
        cout << endl;
    }
};

class manager : public employee2 {
    string title;

public:
    void getdata() {
        employee2::getdata();
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
    }

    void putdata() const {
        employee2::putdata();
        cout << "Title: " << title << endl;
    }
};

class scientist : public employee2 {
    int publications;

public:
    void getdata() {
        employee2::getdata();
        cout << "Enter number of publications: ";
        cin >> publications;
    }

    void putdata() const {
        employee2::putdata();
        cout << "Publications: " << publications << endl;
    }
};

class laborer : public employee2 {
public:
    void getdata() {
        employee2::getdata();
    }

    void putdata() const {
        employee2::putdata();
    }
};

int main() {
    manager m;
    scientist s;
    laborer l;

    cout << "Enter manager data:\n";
    m.getdata();

    cout << "\nEnter scientist data:\n";
    s.getdata();

    cout << "\nEnter laborer data:\n";
    l.getdata();

    cout << "\nManager details:\n";
    m.putdata();

    cout << "\nScientist details:\n";
    s.putdata();

    cout << "\nLaborer details:\n";
    l.putdata();

    return 0;
}
