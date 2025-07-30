#include<iostream>
using namespace std;
template < typename T > 
class Queue{
    private:
    int capacity;
    int read;
    int write;
    T *queue;


    public:
    Queue(){
        capacity = 3;
        read = 0;
        write = 0;
        queue = new T[capacity];
    }



    void enqueue(T value){
        if(write >= capacity){
            throw out_of_range("queue overflow");
        }
        else{
            queue[write] = value;
            write++;
        }
    }



    T dequeue(){
        if(read == write){
            throw out_of_range("dequeue is not valid for empty queue");
        }
        else{
            read++;
            return queue[read-1];
        }
    }




    void showElements(){
        for(int i = read;i < write;i++){
            cout << queue[i] << " ";
        }
    }



    bool empty(){
        if(read == write){
            return true;
        }
        else{
            return false;
        }
    }



    bool full(){
        if(write >= capacity){
            return true;
        }
        else{
            return false;
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
    cout << endl;
    cout << q.full() << endl;
    cout << endl;;
}