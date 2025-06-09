#include<iostream>
using namespace std;
#define MAXSIZE 50
class Deques{
    private:
    int front =-1;
    int rear = -1;
    int array[MAXSIZE];

    public:
    bool checkempty(){
        if(front ==-1){
            return 0;
        }
        else{
            return 1;
        }
    }
    bool checkfull(){
        if(front ==0 && rear == MAXSIZE-1 || front == rear +1){
            return 0;
        }
        else{
            return 1;
        }
    }
    void finsert(int num){
        if(!checkfull())
        {
            cout<<"Queue is full";
            return;

        }
        else if(!checkempty()){
            front =0;
            rear = 0;
        }
        else if(front==0){
            front = MAXSIZE-1;
        }
        else{
            front = front -1;
        }
        array[front]= num;
    

    }
    void rinsert(int num){
        if(!checkfull())
        {
            cout<<"Queue is full";
            return;

        }
        else if(!checkempty()){
            front =0;
            rear = 0;
        }
        else if(rear==MAXSIZE-1){
            rear = 0;
        }
        else{
            rear = rear +1;
        }
        array[rear]= num;
    

    }
    int rremove(){
        if(!checkempty()){
            cout<<"Queue is empty";
            return -1;
        }
            int item = array[rear];
        if(front == rear ){
            front =-1;
            rear =-1;
        }
        else if(rear ==0){
            rear = MAXSIZE-1;
        }
        else {
          rear = rear-1;
        }
    
        return item;
    }
    int fremove(){
        if(!checkempty()){
            cout<<"Queue is empty";
            return -1;
        }
        int item = array[front];
        if(front == rear ){
            front =-1;
            rear =-1;
        }
        else if(front ==MAXSIZE-1){
            front =0;
        }
        else {
          front = front+1;
        }
        
        return item;
    }
    
};
int main() {
    Deques dq;
    dq.rinsert(10);
    dq.rinsert(20);
    dq.rinsert(30);
    dq.finsert(5);
    dq.finsert(2);
    cout << "Removed from rear: " << dq.rremove() << endl;
    cout << "Removed from front: " << dq.fremove() << endl;
    dq.rinsert(40);
    dq.finsert(1);
    cout << "Removed from rear: " << dq.rremove() << endl;
    cout << "Removed from front: " << dq.fremove() << endl;

    return 0;
}
