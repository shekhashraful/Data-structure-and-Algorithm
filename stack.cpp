#include<iostream>
#include<stdexcept>
using namespace std;
template < typename T >
class Stack{
    private:

    T *stack;
    int top;
    int capacity;


    public:


    Stack(){
        capacity = 1000;
        stack = new T[capacity];
        top = -1;
    }

    void push(T item){
        top++;
        if(top == capacity){
            throw out_of_range("stack overflow");
        }
        else{
            stack[top] = item;
        }
    }


    T pop(){
        T value = stack[top];
        if(top == -1){
            throw out_of_range("stack underflow");
        }
        else{
            top--;
            return value;
        }
    }


    int size(){
        return top + 1;
    }

    T pick(){
        
        if(top == -1){
            throw out_of_range("Empty stack");
        }
        return stack[top];
    }

    bool empty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    void showElements()
    {
        for(int i = 0;i <= top;i++){
            cout << stack[i] << " ";
        }
    }

};

int main()
{
    Stack < int > s;
    s.push(10);
    s.push(30);
    s.push(40);
    s.showElements();
    cout << endl;
    cout << s.empty();
    
}