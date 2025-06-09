#include<iostream>
using namespace std;
#define MAXSIZE 6
class CircularQueue{
    private:
    int front =-1;
    int rear = -1;
    int array[MAXSIZE];
    public:
      void insert(int num){
        if(front ==0 && rear == MAXSIZE-1 || front ==rear+1){
            cout<<"Overflow error";
            return;
        }
        else if(front ==-1 && rear ==-1){
            front =0;
            rear = 0;
        }
        else if(rear ==MAXSIZE-1 && front !=0){
            rear =0;
        }
        else{
            rear = rear+1;
            
        }
        array[rear]=num;
      }
      int remove(){
        if(front ==-1){
            cout<<"Circular queue underflow";
            return -1;
        }
        int item = array[front];
        if(front ==rear){
            front =-1;
            rear = -1;

        }
        else if(front ==MAXSIZE-1){
            front =0;
        }
        else{
            front = front +1;
        }
        return item;
      }

};
int main(){
    CircularQueue queue;
    int removed_item;
    queue.insert(30);
    queue.insert(40);
    queue.insert(50);
    queue.insert(60);
    queue.insert(70);
    removed_item = queue.remove();
    cout<<removed_item<<endl;
    queue.insert(80);
    queue.remove();
    queue.remove();
    queue.remove();
    queue.remove();
   int last_item =  queue.remove();
   cout<<last_item;


}