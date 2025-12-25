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
        std::strcpy(str, s);
    }

    void display() const {
        cout << str << endl;
    }
};

class Pstring : public String {
public:
    Pstring() : String() {}

    Pstring(const char s[]) {
        if (std::strlen(s) < SZ)
            std::strcpy(str, s);
        else {
            std::strncpy(str, s, SZ - 1);
            str[SZ - 1] = '\0';
        }
    }
};

class Pstring2 : public Pstring {
public:
    Pstring2() : Pstring() {}
    Pstring2(const char s[]) : Pstring(s) {}

    Pstring2& left(const Pstring2& s1, int n) {
        int len = std::strlen(s1.str);
        if (n > len) n = len;
        if (n >= SZ) n = SZ - 1;

        for (int i = 0; i < n; i++)
            str[i] = s1.str[i];

        str[n] = '\0';
        return *this;
    }

    Pstring2& mid(const Pstring2& s1, int start, int n) {
        int len = std::strlen(s1.str);

        if (start < 0 || start >= len) {
            str[0] = '\0';
            return *this;
        }

        if (start + n > len)
            n = len - start;

        if (n >= SZ)
            n = SZ - 1;

        for (int i = 0; i < n; i++)
            str[i] = s1.str[start + i];

        str[n] = '\0';
        return *this;
    }

    Pstring2& right(const Pstring2& s1, int n) {
        int len = std::strlen(s1.str);
        if (n > len) n = len;
        if (n >= SZ) n = SZ - 1;

        int start = len - n;
        for (int i = 0; i < n; i++)
            str[i] = s1.str[start + i];

        str[n] = '\0';
        return *this;
    }
};

int main() {
    Pstring2 s1("Inheritance makes C++ powerful");
    Pstring2 s2;

    s2.left(s1, 11);
    cout << "Left: ";
    s2.display();

    s2.mid(s1, 12, 5);
    cout << "Mid: ";
    s2.display();

    s2.right(s1, 9);
    cout << "Right: ";
    s2.display();

    return 0;
}
