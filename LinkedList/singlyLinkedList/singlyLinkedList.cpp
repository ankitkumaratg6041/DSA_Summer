#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node() {
        int value = this->data;
        if(this->next != NULL){
            this->next = NULL;
            delete next;
        }
        cout << "Node with a value: " << value << " deleted" << endl;
    }
};

/*
    ## Insertion in Singly Linked List ##
    - Insert at head
    - Insert at tail
    - Insert in the middle

    ## Delection in Singly Linked List ##
    - Deletion at head
    - Deletion at tail
    - Deletion in the middle

    -> Traversal in Singly Linked List
    -> Printing the Singly Linked List
*/

void insertAtHead(Node* &head, int data){
    // create a new node with data
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    // tail = temp; 
    tail = tail->next;      // both ways it is correct
}

void insertInMiddle(Node* &head, Node* &tail,int data, int pos){
    if(pos == 1){
        insertAtHead(head, data);
        return;
    }
    Node* newNode = new Node(data);
    Node* temp = head; // Kind of iterator
    int count = 0;
    while(count < pos-1){ // couting till a node before
        temp = temp->next;
        count++;
    }
    if(temp->next == NULL){ // OR if(len == pos-1) if and only if you know the length of list
        insertAtTail(tail, data);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(int pos, Node* &head, Node* &tail){
    if(pos == 1){
        // deleting head node
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else{
        // deleting middle node
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < pos){
            prev = curr;
            curr = curr->next;
            count++;
        }
        if(curr->next == NULL){
            tail = prev;
        }
        prev->next = curr->next;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    // creating a single node
    Node* node = new Node(20);
    // cout << "data: " << node->data << endl;
    // cout << "next: " << node->next << endl;

    // Creating a chain of node
    Node* head = node;
    Node* tail = node;
    insertAtHead(head, 10);
    insertAtHead(head, 30);
    insertAtHead(head, 60);
    print(head);

    insertAtTail(tail, 93);
    insertAtTail(tail, 94);
    insertAtTail(tail, 95);
    insertAtTail(tail, 96);
    print(head);

    insertInMiddle(head, tail, 107, 1);
    insertInMiddle(head, tail, 105, 3);
    // insertInMiddle(head, tail, 106, 6);
    insertInMiddle(head, tail, 10006, 10);

    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl << endl;

    cout<< "Before deletion: " << endl;
    print(head);
    deleteNode(11, head, tail);
    cout<< "After deletion: " << endl;
    print(head);

    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    return 0;
}