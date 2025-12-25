
#include <iostream>
#include <string>
using namespace std;

class employee {
protected:
    string name;
    int emp_number;

public:
    void getdata() {
        cout << "Enter employee name: ";
        getline(cin, name);
        cout << "Enter employee number: ";
        cin >> emp_number;
        cin.ignore();
    }

    void putdata() const {
        cout << "Employee name: " << name << endl;
        cout << "Employee number: " << emp_number << endl;
    }
};

class manager : public employee {
protected:
    string title;
    double dues;

public:
    void getdata() {
        employee::getdata();
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter dues: ";
        cin >> dues;
        cin.ignore();
    }

    void putdata() const {
        employee::putdata();
        cout << "Title: " << title << endl;
        cout << "Dues: " << dues << endl;
    }
};

class executive : public manager {
    double yearly_bonus;
    int stock_options;

public:
    void getdata() {
        manager::getdata();
        cout << "Enter yearly bonus: ";
        cin >> yearly_bonus;
        cout << "Enter number of stock options: ";
        cin >> stock_options;
        cin.ignore();
    }

    void putdata() const {
        manager::putdata();
        cout << "Yearly bonus: $" << yearly_bonus << endl;
        cout << "Stock options: " << stock_options << endl;
    }
};

int main() {
    executive e;

    cout << "Enter executive data:\n";
    e.getdata();

    cout << "\nExecutive details:\n";
    e.putdata();

    return 0;
}
