#include <iostream>
using namespace std;

class Token {
public:
    virtual float getNumber() = 0;
    virtual char getOperator() = 0;
    virtual ~Token() {}
};

class Operator : public Token {
private:
    char oper;
public:
    Operator(char c) : oper(c) {}
    char getOperator() override { return oper; }
    float getNumber() override { return 0.0; }
};

class Number : public Token {
private:
    float fnum;
public:
    Number(float f) : fnum(f) {}
    float getNumber() override { return fnum; }
    char getOperator() override { return '\0'; }
};

class Stack {
private:
    Token* stk[100];
    int top;
public:
    Stack() : top(-1) {}

    void push(Token* t) {
        if (top < 99) stk[++top] = t;
        else cout << "Stack overflow\n";
    }

    Token* pop() {
        if (top >= 0) return stk[top--];
        cout << "Stack underflow\n";
        return nullptr;
    }

    bool isEmpty() { return top == -1; }
};

int main() {
    Stack s;

    s.push(new Number(3.14159f));
    s.push(new Operator('+'));
    s.push(new Number(2.0f));
    s.push(new Operator('*'));
    s.push(new Number(5.5f));

    while (!s.isEmpty()) {
        Token* t = s.pop();
        if (t->getOperator() != '\0') cout << "Operator: " << t->getOperator() << endl;
        else cout << "Number: " << t->getNumber() << endl;
        delete t;
    }

    return 0;
}
