#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

class Token {
public:
    virtual float getNumber() = 0;
    virtual char getOperator() = 0;
    virtual ~Token() {}
};

class Number : public Token {
    float value;
public:
    Number(float v) : value(v) {}
    float getNumber() override { return value; }
    char getOperator() override { return '\0'; }
};

class Operator : public Token {
    char op;
public:
    Operator(char c) : op(c) {}
    float getNumber() override { return 0.0f; }
    char getOperator() override { return op; }
};

// Function to evaluate a simple postfix expression
float evaluateExpression(const string& expr) {
    stack<Token*> s;
    istringstream iss(expr);
    string tok;

    while (iss >> tok) {
        if (isdigit(tok[0]) || (tok[0] == '.' || (tok[0] == '-' && tok.size() > 1))) {
            float num = stof(tok);
            s.push(new Number(num));
        } else {
            char op = tok[0];
            Token* t2 = s.top(); s.pop();
            Token* t1 = s.top(); s.pop();
            float n2 = t2->getNumber();
            float n1 = t1->getNumber();
            float res = 0.0;

            switch (op) {
                case '+': res = n1 + n2; break;
                case '-': res = n1 - n2; break;
                case '*': res = n1 * n2; break;
                case '/': res = n1 / n2; break;
            }
            s.push(new Number(res));
            delete t1;
            delete t2;
        }
    }

    float result = s.top()->getNumber();
    delete s.top();
    return result;
}

int main() {
    string expr;
    cout << "Enter a postfix expression with floats (e.g., 3.5 2.0 + 4.1 *): ";
    getline(cin, expr);

    float result = evaluateExpression(expr);
    cout << "Result: " << result << endl;

    return 0;
}
