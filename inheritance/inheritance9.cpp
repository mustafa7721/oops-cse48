
#include <iostream>
#include <string>
using namespace std;

class date {
public:
    int month;
    int day;
    int year;

    void getdate() {
        cout << "Enter month (1-12): ";
        cin >> month;
        cout << "Enter day (1-31): ";
        cin >> day;
        cout << "Enter year: ";
        cin >> year;
        cin.ignore();
    }

    void putdate() const {
        cout << month << "/" << day << "/" << year;
    }
};

class publication2 {
protected:
    string title;
    float price;
    date pubdate;

public:
    void getdata() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cin.ignore();
        cout << "Enter publication date:\n";
        pubdate.getdate();
    }

    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
        cout << "Publication date: ";
        pubdate.putdate();
        cout << endl;
    }
};

class book : public publication2 {
    int page_count;

public:
    void getdata() {
        publication2::getdata();
        cout << "Enter page count: ";
        cin >> page_count;
        cin.ignore();
    }

    void putdata() const {
        publication2::putdata();
        cout << "Page count: " << page_count << endl;
    }
};

class tape : public publication2 {
    float playing_time;

public:
    void getdata() {
        publication2::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playing_time;
        cin.ignore();
    }

    void putdata() const {
        publication2::putdata();
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
