#include <iostream>
using namespace std;

#define MAXSIZE 50

class Queue
{
private:
    int front = 0;
    int rear = -1;
    int array[MAXSIZE];

public:
    void insert(int num)
    {
        if (rear == MAXSIZE - 1)
        {
            cout << "Overflow error";
            return;
        }
        rear = rear + 1;
        array[rear] = num;
        return;
    }
    void remove()
    {
        if (rear == -1 || front > rear)
        {
            cout << "Underflow error";
            return;
        }
        int item = array[front];
        front = front + 1;
        return;
    }
    int peek()
    {
        if (rear == -1 || front > rear)
        {
            cout << "There is no element";
            return -1;
        }
        int item = array[front];
        return item;
    }
};
int main()
{
    Queue queue;
    int number;
    queue.insert(20);
    queue.insert(30);
    queue.insert(40);
    number = queue.peek();
    cout << number << endl;
    queue.remove();
    int number1 = queue.peek();
    cout << number1 << endl;
    
}