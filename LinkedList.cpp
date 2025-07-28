#include<iostream>
#include<stdexcept>
using namespace std;
template < typename T >
class List{

    private:
    struct node{
        T data;
        node *next;
    };
    node *newNode, *temp, *tail, *head, *temp1, *temp2, *leftNode, *rightNode, *x;
    int Size;
    T value;


    
    public:
    List(){
        head = nullptr;
        newNode = nullptr;
        temp = nullptr;
        temp1 = nullptr;
        temp2 = nullptr;
        tail = nullptr;
        x = nullptr;
        Size = 0;
    }


    void push_back(T item){
        newNode = new node;
        newNode->data = item;
        newNode->next = nullptr;
        if(head == nullptr){
            head = newNode;
        }
        else{
            temp->next = newNode;
        }
        temp = newNode;
        Size++;
    }

    
    void showElements(){
        temp1 = head;
        for(int i = 0;i < Size;i++){
            cout << temp1->data << " ";
            temp1 = temp1->next;
        }
    }


    int size(){
        return Size;
    }


    bool empty(){
        if(Size == 0){
            return true;
        }
        return false;
    }

    
    T value_at(int index){
        if(index < 0 || index >= Size){
            throw out_of_range("Given index doesn't exist");
        }
        else{
            temp1 = head;
            for(int i = 0;i < index;i++){
                temp1 = temp1->next;

            }
            return temp1->data;
        }
    }


    void push_front(T value){
        if(head == nullptr){
            newNode = new node;
            newNode->data = value;
            head = newNode;
        }
        else{
            newNode = new node;
            newNode->data = value;
            newNode->next = head;
            head = newNode;
        }
        Size++;
    }


    T pop_front(){
        if(Size == 0){
            throw out_of_range("Empty List");
        }
        else{
            temp1 = head;
            value = head->data;
            head = head->next;
            delete temp1;
            Size--;
            return value;
        }
    }


    T pop_back(){
        if(Size == 0){
            throw out_of_range("Empty list");
        }
        else{
            tail = findTail();
            value = tail->data;
            delete tail;
            Size--;
            return value;
        }
    }


    node * findTail(){
        temp1 = head;
        for(int i = 1;i < Size;i++){
            temp1 = temp1->next;
        }
        return temp1;
    }


    T front(){
        return head->data;
    }


    T back(){
        tail = findTail();
        return tail->data;
    }


    void insert(int index , T value){
        if(index < 0 || index > Size){
            throw out_of_range("Invalid index insertion");
        }
        else{
            if(index == 0){
                push_front(value);
            }
            else if(index == Size){
                push_back(value);
            }
            else if(index == 1){
                newNode = new node;
                newNode->data = value;
                leftNode = head;
                rightNode = leftNode->next;
                leftNode->next = newNode;
                newNode->next = rightNode;

                Size++;
            }
            else{
                temp1 = head;
                for(int i = 0;i < index;i++){
                    temp1 = temp1->next;
                    if(i == index - 2){
                        leftNode = temp1;
                    }
                    else if(i == index - 1){
                        rightNode = temp1;
                    }
                }
                newNode = new node;
                leftNode->next = newNode;
                newNode->data = value;
                newNode->next = rightNode;
                Size++;

            }
        }
    }


    void remove(int index){
        if(index < 0 || index >= Size){
            throw out_of_range("Given index doesn't exist");
        }
        else{
            if(index == 0){
                pop_front();
            }
            else if(index == Size - 1){
                pop_back();
            }
            else{
                temp1 = head;
                for(int i = 1;i < index;i++){
                    temp1 = temp1->next;
                }
                rightNode = temp1->next;
                temp1->next = rightNode->next;
                delete rightNode;
                Size--;
            }
        }
    }


    T value_n_from_end(int n){
        if(n <= 0 || n > Size){
            throw out_of_range("Invalid position");
        }
        else{
            int index;
            index = Size - n;
            temp1 = head;
            for(int i = 1;i <= index;i++){
                temp1 = temp1->next;
            }
            return temp1->data;
        }
    }


    void Reverse(){
        temp1 = head;
        for(int i = 1;i < Size;i++){
             temp1 = temp1->next;
             push_front(temp1->data);
             Size--;
        }
    }


    void reverse()
    {
        temp1 = head;
        for(int i = 1;i <= Size;i++){
             x = temp1->next;       
             temp1->next = temp2;   
             temp2 = temp1;        
             temp1 = x;    
        }

        head = temp2;
    }


    void remove_value(T value){
        temp1 = head;
        for(int i = 0;i < Size;i++){
            if(temp1->data == value){
                remove(i);
                break;
            }
            temp1 = temp1->next;
        }
    }

};
int main()
{
    List < int > list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.showElements();
    cout << endl;
    list.remove_value(4);
    cout << endl;
    list.showElements();
    cout << endl;
    



}