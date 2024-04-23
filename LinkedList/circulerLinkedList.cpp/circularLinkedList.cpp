#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    // Node constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    // Node destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory is free with data: " << value << endl;
    }
};

void insertCircularLL(Node* &tail, int nodeVal, int data){
    // empty list
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        temp->next = temp;
    }
    else{
        Node* temp = new Node(data);
        Node* curr = tail; // for traversal and finding nodeVal
        while(curr->data != nodeVal){
            curr = curr->next;
            if(curr == tail){
                cout << "Invalid node value entered!" << endl;
                return;
            }
        }
        // if(curr == tail){ // ---> this doesn't make sense as circular LL doesn't have any start or end so just let tail be wherever it is
        //     temp->next = curr->next;
        //     curr->next = temp;
        //     tail = temp;
        // }
            temp->next = curr->next;
            curr->next = temp;
    }
}

void deleteCirculerLL(Node* &tail, int nodeVal){
    if(tail == NULL){
        cout << "Empty list!" << endl;
        return;
    }
    else{
        Node* prev = tail;
        Node* curr = tail->next; // for traversal and finding nodeVal
        while(curr->data != nodeVal){
            prev = curr;
            curr = curr->next;
            if(curr == tail->next){
                cout << "Invalid node value entered!" << endl;
                return;
            }
        }
        prev->next = curr->next;
        // for single node deletion
        if(curr == prev){
            tail = NULL;
        }
        // for more than 1 more deletion
        if(curr == tail){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void print(Node* tail){
    if(tail == NULL){
        cout << "Empty list" << endl;
        return;
    }
    Node* temp = tail;
    do{
        cout << tail->data << " ";
        tail = tail->next;
    }while(tail != temp);

    cout << endl;
}

int main(void){
    Node* tail = NULL;

    insertCircularLL(tail, 0, 5);
    print(tail);
    // insertCircularLL(tail, 5, 6);
    // print(tail);
    // insertCircularLL(tail, 6, 7);
    // print(tail);
    deleteCirculerLL(tail, 5);
    print(tail);

    return 0;
}