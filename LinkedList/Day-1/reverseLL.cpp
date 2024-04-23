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

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory free with data: " << value << endl;
    }
};

void insertAtHead(Node* &head, Node* &tail, int data){
    Node* temp = new Node(data);

    if(head == NULL && tail == NULL){
        head = temp;
        tail = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int data){
    Node* temp = new Node(data);

    if(tail == NULL && head == NULL){
        tail = temp;
        head = temp;
    }
    else{
        // this mehtod can be used if no tail is present
        // {Node* itr = head;
        // while(itr->next != NULL){
        //     itr = itr->next;
        // }
        // itr->next = temp;
        // tail = temp;}

        tail->next = temp;
        tail = temp;
    }
}

void insertAtMiddle(Node* &head, Node* &tail, int pos, int data){
    // inserting at head
    if(pos == 1){
        insertAtHead(head, tail, data);
        return;
    }
    Node* temp = new Node(data);
    Node* counter = head;
    int count = 1;

    while(count < pos-1){
        counter = counter->next;
        if(counter == NULL){
            cout << "position out of bounds" << endl;
            return;
        }
        count++;
    }

    // insertion at tail
    if(counter->next == NULL){
        insertAtTail(tail, head, data);
        return;
    }
    else{
        temp->next = counter->next;
        counter->next = temp;
    }
}

void reverseLinkedList(Node* &head, Node* &tail){
    Node* prev = NULL;
    Node* curr = NULL;
    Node* forward = head;

    while(forward != NULL){
        curr = forward;
        forward = forward->next;
        curr->next = prev;
        prev = curr;
    }
    tail = head;
    head = curr;
}

void recursiveReverse(Node* &head, Node* &curr, Node* &prev){
    // base case
    if(curr == NULL){
        head = prev;
        return;
    }

    // processing and 
    Node* forward = curr->next;
    recursiveReverse(head, forward, curr);
    curr->next = prev;
}

void recursiveReverseLL(Node* &head, Node* &tail){
    Node* curr = head;
    Node* prev = NULL;

    tail = head;
    recursiveReverse(head, curr, prev);

}

void print(Node* head){
    const Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(void){
    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter the size of linked list: ";
    int size;
    cin >> size;
    int pos = 1;
    cout << "Enter list items: ";
    while(size--){
        int num = 0;
        cin >> num;
        insertAtMiddle(head, tail, pos++, num);
    }
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    print(head);

    recursiveReverseLL(head, tail);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    print(head);

    return 0;
}