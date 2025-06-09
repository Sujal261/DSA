#include<iostream>
#include<string>
#include<algorithm>
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
int main(){
    Stack s;
    string expression;
    cout<<"Enter the mathematical expression";
    cin>>expression;
    
    for(int i = 0; i<=expression.length();i++){
        char ch = expression[i];
        if(ch=='(')
    {
        s.push(ch);
    }
    
    if(ch==')'&&s.isEmpty()){
        cout<<"Wrong Parenthesis";
        return 0;

    }
    else if(ch ==')'&& s.keep()=='('){
        s.pop();
    }

    }
    if(s.isEmpty()){
    cout<<"Correct Parenthesis";
    }
    else{
        cout<<"Wrong Parenthesis";
    }
    return 0;
    



}