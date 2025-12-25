#include <iostream>
#include <cstring>
using namespace std;

const int SZ = 80;

class StringTooLong {
    const char* message;
public:
    StringTooLong(const char* msg) : message(msg) {}
    const char* what() const { return message; }
};

class String {
    char str[SZ];
public:
    String(const char* s = "") {
        if (strlen(s) >= SZ)
            throw StringTooLong("Initialization string too long");
        strcpy(str, s);
    }

    String operator+(const String &s) const {
        if (strlen(str) + strlen(s.str) >= SZ)
            throw StringTooLong("Resulting string too long after concatenation");
        String temp(str);
        strcat(temp.str, s.str);
        return temp;
    }

    void display() const {
        cout << str << endl;
    }
};

int main() {
    try {
        String s1("Hello");
        String s2(" World!");
        String s3 = s1 + s2;
        s3.display();

        

    } catch (StringTooLong &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
