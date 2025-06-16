#include<iostream>
using namespace std;

struct Node{
    int data ;
    Node* next;

    Node(int val){
        data =val;
        next = nullptr;
    }

};

class LinkedList{
    private:
    Node* head;
    public:
    LinkedList(){
        head = nullptr;
    }
    void insert(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
            return;

        }
        Node* temp = head;
        while(temp->next !=nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insertb(int val){
        Node* newNode = new Node(val);
        if(head ==nullptr){
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void remove(){
        if(head ==nullptr) return;
        if (head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
    
        while(temp->next->next!=nullptr){
           
            temp = temp->next;
            
        }
        delete temp->next;
        temp->next = nullptr;

    }
    void removeb(){
        if(head == nullptr) return;
        if (head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        

    }
    void addafter(int val, int value ){
        Node* temp = head;
        Node* newNode = new Node(value);
        while(temp->data != val){
            temp = temp->next;
        }
        if (temp == nullptr) {
        std::cout << "Value " << val << " not found.\n";
        return;
    }
        newNode->next = temp->next;
        temp->next = newNode;


    }
    void addbefore(int val, int value){
        Node* temp = head;
        Node* newNode = new Node(value);
        while(temp->next->data != val){
            temp = temp->next;
        }
        if (temp == nullptr) {
        std::cout << "Value " << val << " not found.\n";
        return;
    }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void Display(){
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"Null"<<endl;
    }

};
int main(){
    LinkedList list;
    list.insert(20);
    list.insert(30);
     list.insertb(40);
     list.remove();
     list.insertb(50);
    list.Display();
    list.removeb();
    list.Display();
    list.addafter(40, 25);
    list.Display();
    list.addbefore(25, 90);
    list.Display();
   
}