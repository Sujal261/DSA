#include<iostream>
using namespace std;
#define MAX 100
class Stack{
    private:
        int top=-1;
        int array[MAX];
    
    public:
        void push(int x){
            if(top>(MAX-1))
            {
                cout<<"Overflow error";
                return;
            }
            array[++top]=x;
        }
        void pop(){
            if(top<0){
                cout<<"Underflow error";
                return;
            }
            top--;
        }
        int keep(){
            if(top<0){
                cout<<"Stack is empty";
                return -1;
            }
            return array[top];
        }

};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    cout<<"THe value at top of stack is "<<s.keep()<<endl;
    s.pop();
    cout<<"The value after pop is"<<s.keep()<<endl;
    return 0;
}