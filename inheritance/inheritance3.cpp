
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

class sales {
protected:
    float sales_data[3];

public:
    void getdata() {
        cout << "Enter sales for last three months:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Month " << i + 1 << ": ";
            cin >> sales_data[i];
        }
        cin.ignore();
    }

    void putdata() const {
        cout << "Sales data:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Month " << i + 1 << ": $" << sales_data[i] << endl;
        }
    }
};

class book : public publication, public sales {
    int page_count;

public:
    void getdata() {
        publication::getdata();
        cout << "Enter page count: ";
        cin >> page_count;
        sales::getdata();
    }

    void putdata() const {
        publication::putdata();
        cout << "Page count: " << page_count << endl;
        sales::putdata();
    }
};

class tape : public publication, public sales {
    float playing_time;

public:
    void getdata() {
        publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playing_time;
        sales::getdata();
    }

    void putdata() const {
        publication::putdata();
        cout << "Playing time: " << playing_time << " minutes" << endl;
        sales::putdata();
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
