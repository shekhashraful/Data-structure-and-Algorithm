#include<iostream>
using namespace std;
template < typename T >
class Queue{
    private:
    struct node{
       T data;
       node * next; 
    };
    node *head, *tail, *newNode;




    public:
    Queue(){
        head = nullptr;
        tail = nullptr;
        newNode = nullptr;
    }


    void enqueue( T value){
        newNode = new node;
        newNode->data = value;
        if(head == nullptr){
            head = newNode;
            tail = newNode;
            tail->next = nullptr;
        }
        else{
            tail->next = newNode;
            tail = newNode;
            tail->next = nullptr;
        }
    }


    
    T dequeue(){
        node *temp;
        T value;
        if(head == nullptr){
            throw out_of_range("dequeue is not valid for empty queue");
        }
        else{
            temp = head;
            value = head->data;
            head = temp->next;
            delete temp;
            return value;
        }
    }



    bool Empty(){
        if(head == nullptr){
            return true;
        }
        else{
            return false;
        }
    }
    
    void showElements(){
        node * temp;
        temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }


};
int main()
{
    Queue < int > q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.showElements();
}