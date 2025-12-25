
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

    virtual ~publication() {}
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
    const int MAX_ITEMS = 10;
    publication* pubarr[MAX_ITEMS];
    int count = 0;
    char choice;

    do {
        if (count >= MAX_ITEMS) break;

        cout << "Enter 'b' for book or 't' for tape: ";
        cin >> choice;
        cin.ignore();

        if (choice == 'b' || choice == 'B')
            pubarr[count] = new book;
        else if (choice == 't' || choice == 'T')
            pubarr[count] = new tape;
        else continue;

        pubarr[count]->getdata();
        count++;

        cout << "Do you want to enter another item? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y' || choice == 'Y');

    for (int i = 0; i < count; i++) {
        cout << "\nItem " << i + 1 << ":\n";
        pubarr[i]->putdata();
    }

    for (int i = 0; i < count; i++)
        delete pubarr[i];

    return 0;
}
