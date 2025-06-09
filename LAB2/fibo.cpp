#include<iostream>
using namespace std;

int fibo(int num){
    if (num ==0 || num ==1){
        return num;    }
        else{
            return fibo(num-1)+fibo(num-2);
        }
}

int main()
{
    int n , result;
    cout<<"enter the nth place for fibonacci number"<<endl;
    cin>>n;
    result =fibo(n);
    cout<<"the number is"<<result;
    return 0;
}