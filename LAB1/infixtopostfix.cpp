#include<iostream>
#include<string>
using namespace std;
#define MAX 100

class Stack {
private:
    int top = -1;
    char array[MAX];

public:
    void push(char x) {
        if (top >= MAX - 1) {
            cout << "Overflow error";
            return;
        }
        array[++top] = x;
    }

    void pop() {
        if (top < 0) {
            cout << "Underflow error";
            return;
        }
        top--;
    }

    char keep() {
        if (top < 0) {
            return '\0';
        }
        return array[top];
    }

    bool isEmpty() {
        return top < 0;
    }
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

string checkthestring(char c, Stack &s, string &postfix) {
    if (isalnum(c)) {
        return string(1, c);
    }

    if (c == '(') {
        s.push(c);
        return "";
    }

    if (c == ')') {
        string temp = "";
        while (!s.isEmpty() && s.keep() != '(') {
            temp += s.keep();
            s.pop();
        }
        if (!s.isEmpty() && s.keep() == '(') s.pop(); 
        return temp;
    }

    if (isOperator(c)) {
        string temp = "";
        while (!s.isEmpty() && precedence(s.keep()) >=precedence(c)) {
            temp += s.keep();
            s.pop();
        }
        s.push(c);
        return temp;
    }

    return "";
}

int main() {
    Stack s;
    string infixexpression;
    string postfixexpression;
    cout << "Enter the expression: ";
    getline(cin, infixexpression); 

    for (int i = 0; i < infixexpression.length(); i++) {
        char ch = infixexpression[i];
        if (ch == ' ') continue; 
        postfixexpression += checkthestring(ch, s, postfixexpression);
    }

    
    while (!s.isEmpty()) {
        if (s.keep() != '(') 
            postfixexpression += s.keep();
        s.pop();
    }

    cout << "The postfix expression is: " << postfixexpression << endl;
    return 0;
}
