
#include <iostream>
#include <string>
using namespace std;

class publication {
protected:
    string title;
    float price;

public:
    void getdata() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cin.ignore();
    }

    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

class book : public publication {
    int page_count;

public:
    void getdata() {
        publication::getdata();
        cout << "Enter page count: ";
        cin >> page_count;
        cin.ignore();
    }

    void putdata() const {
        publication::putdata();
        cout << "Page count: " << page_count << endl;
    }
};

class tape : public publication {
    float playing_time;

public:
    void getdata() {
        publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playing_time;
        cin.ignore();
    }

    void putdata() const {
        publication::putdata();
        cout << "Playing time: " << playing_time << " minutes" << endl;
    }
};

class disk : public publication {
    enum disktype { CD, DVD } dtype;

public:
    void getdata() {
        publication::getdata();
        char ch;
        cout << "Enter disk type (c for CD, d for DVD): ";
        cin >> ch;
        cin.ignore();
        dtype = (ch == 'c' || ch == 'C') ? CD : DVD;
    }

    void putdata() const {
        publication::putdata();
        cout << "Disk type: " << (dtype == CD ? "CD" : "DVD") << endl;
    }
};

int main() {
    book b;
    tape t;
    disk d;

    cout << "Enter book data:\n";
    b.getdata();

    cout << "\nEnter tape data:\n";
    t.getdata();

    cout << "\nEnter disk data:\n";
    d.getdata();

    cout << "\nBook details:\n";
    b.putdata();

    cout << "\nTape details:\n";
    t.putdata();

    cout << "\nDisk details:\n";
    d.putdata();

    return 0;
}
