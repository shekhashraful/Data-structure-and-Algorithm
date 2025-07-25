#include<iostream>
#include<stdexcept>
using namespace std;

template < typename T >

class Vector{

    private:

    T* array;
    int size;
    int capacity;

    public:

    Vector()
    {
        size = 0;
        capacity = 16;
        array = new T[capacity];
    }


    void push_back(T value)
    {
        if(size == capacity){
            resizeArray();
        }
        array[size++] = value;
    }


    void resizeArray()
    {
        T* temp;
        capacity = 2 * capacity;
        temp = new T[capacity];
        for(int i = 0;i < size;i++){
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
        
    }


    void showElements()
    {
        for(int i = 0;i < size;i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }


    int length()
    {
        return size;
    }


    int Capacity()
    {
        return capacity;
    }


    bool isEmpty()
    {
        if(size == 0){
            return true;
        }
        return false;
    }

    T at(int index)
    {
        if(index < 0 || index > size){
            throw out_of_range("Index is out of range !");
        }
        else{
            return array[index];
        }
    }


    void insert(int index , T item)
    {
        T temp;
        int lastIndex;
        if(size == capacity){
            resizeArray();
        }
        for(int i = index;i < size;i++){
            temp = array[i];
            array[i] = item;
            item = temp;
            lastIndex = i + 1;

        }
        array[lastIndex] = item;
        size++;
    }


    void prepend(T item)
    {
        T temp;
        int lastIndex;
        if(size == capacity){
            resizeArray();
        }
        for(int i = 0;i < size;i++){
            temp = array[i];
            array[i] = item;
            item = temp;
            lastIndex = i + 1;
        }
        array[lastIndex] = item;
        size++;
    }


    T pop_back()
    {
        if(size == 0){
            throw out_of_range("pop_back operation is not valid for empty array");
        }
        else{
            T temp;
            temp = array[size-1];
            array[size-1] = 0;
            size--;
            return temp;
        }
        if(size == capacity / 4){
            capacity = capacity / 2;
        }
    }


    void deleteIndex(int index)
    {
        if(index == size-1){
            array[index] = 0;
        }
        if(index < 0 || index >= size){
            throw out_of_range("Index is out of range");
        }
        else{
            for(int i = index;i < size - 1;i++){
            array[i] = array[i+1];
           }
        }

        size--;
    }


    int find(T item)
    {
        for(int i = 0;i < size;i++){
            if(array[i] == item){
                return i;
            }
        }
        return -1;
    }

    void remove(T item)
    {
        for(int i = 0;i < size;i++){
            if(array[i] == item){
                deleteIndex(i);
                i--;
            }
        }
    }

    T& operator[](int index){
        if(index < 0 || index >= size){
            throw out_of_range("Index is out of range!");
        }
        else{
            return array[index];
        }
    }

};

