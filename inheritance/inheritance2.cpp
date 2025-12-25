
#include <iostream>
#include <cstring>
using namespace std;

const int SZ = 80;

class String {
protected:
    char str[SZ];

public:
    String() {
        str[0] = '\0';
    }

    String(const char s[]) {
        strcpy(str, s);
    }

    void display() const {
        cout << str << endl;
    }
};

class Pstring : public String {
public:
    Pstring(const char s[]) {
        if (strlen(s) < SZ)
            strcpy(str, s);
        else {
            strncpy(str, s, SZ - 1);
            str[SZ - 1] = '\0';
        }
    }
};

int main() {
    Pstring s1("Short string");
    Pstring s2("This string will surely exceed the width of the screen, which is what the SZ constant represents.");

    cout << "String 1:\n";
    s1.display();

    cout << "\nString 2:\n";
    s2.display();

    return 0;
}
