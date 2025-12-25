
#include <iostream>
#include <string>
using namespace std;

class publication {
protected:
    string title;
    float price;

public:
    virtual void getdata() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cin.ignore();
    }

    virtual void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

class book : public publication {
    int page_count;

public:
    void getdata() override {
        publication::getdata();
        cout << "Enter page count: ";
        cin >> page_count;
        cin.ignore();
    }

    void putdata() const override {
        publication::putdata();
        cout << "Page count: " << page_count << endl;
    }
};

class tape : public publication {
    float playing_time;

public:
    void getdata() override {
        publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playing_time;
        cin.ignore();
    }

    void putdata() const override {
        publication::putdata();
        cout << "Playing time: " << playing_time << " minutes" << endl;
    }
};

int main() {
    book b;
    tape t;

    cout << "Enter book data:\n";
    b.getdata();

    cout << "\nEnter tape data:\n";
    t.getdata();

    cout << "\nBook details:\n";
    b.putdata();

    cout << "\nTape details:\n";
    t.putdata();

    return 0;
}
