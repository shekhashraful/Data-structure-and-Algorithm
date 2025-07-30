#include<iostream>
using namespace std;
template < typename T >
class Queue{
    private:
    int capacity;
    T *queue;
    int write;
    int read;
    int count;



    public:
    Queue(){
        capacity = 5;
        write = 0;
        read = 0;
        count = 0;
        queue = new T[capacity];
    }



    void enqueue(T value){
        if(count == capacity){
            throw out_of_range("Queue is already full.");
        }
        else{
            queue[write] = value;
            write = (write + 1) % capacity;
            count++;
        }
    }



    T dequeue(){
        T value;
        if(count == 0){
            throw out_of_range("Queue is already empty");
        }
        else{
            value = queue[read];
            read = (read + 1) % capacity;
            count--;
            return value;
        }   
    }



    bool empty(){
        if(count == 0){
            return true;
        }
        else{
            return false;
        }
    }


    bool full(){
        if(count == capacity){
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
    int value;
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> value;
        q.enqueue(value);

    }


}