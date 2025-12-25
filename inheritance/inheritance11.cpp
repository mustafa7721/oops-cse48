#include <iostream>
using namespace std;

const int MAX = 100;

struct IntPair { // renamed from 'pair' to 'IntPair'
    int x;
    int y;
};

class Stack2 {
protected:
    int st[MAX];
    int top;

public:
    Stack2() : top(-1) {}

    void push(int n) {
        if (top >= MAX - 1) {
            cout << "Stack overflow\n";
            return;
        }
        st[++top] = n;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack underflow\n";
            return 0;
        }
        return st[top--];
    }
};

class pairStack : public Stack2 {
public:
    void push(const IntPair& p) {
        Stack2::push(p.x);
        Stack2::push(p.y);
    }

    IntPair pop() {
        IntPair p;
        p.y = Stack2::pop();
        p.x = Stack2::pop();
        return p;
    }
};

int main() {
    pairStack ps;
    IntPair p1 = {10, 20};
    IntPair p2 = {30, 40};

    ps.push(p1);
    ps.push(p2);

    IntPair r;

    r = ps.pop();
    cout << "Popped pair: (" << r.x << ", " << r.y << ")\n";

    r = ps.pop();
    cout << "Popped pair: (" << r.x << ", " << r.y << ")\n";

    return 0;
}
