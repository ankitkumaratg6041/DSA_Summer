#include <iostream>
using namespace std;

class Node{
 public:
    int data; 
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        delete next;
        cout << "Node with value " << data << " deleted.";
    }
};

void insertAtHead(Node* &head, Node* &tail, int data){
    Node* temp = new Node(data);
    temp->next = head;
    // if list is empty
    if(head == NULL){
        tail = temp;
    }
    head = temp;
}

void insertAtTail(Node* &tail, Node* &head, int data){
    Node* temp = new Node(data);

    // empty list
    if(tail == NULL){
        head = temp;
    }
    else{
        tail->next = temp;
    }
    tail = temp;
}

void insertAtMiddle(Node* &head, Node* &tail, int pos, int data){
    // inserting at head
    if(pos == 1){
        insertAtHead(head, tail, data);
        return;
    }

    // otherwise count till pos
    Node* temp = new Node(data);
    Node* counter = head;
    int count = 1;
    while(count < pos-1){
        counter = counter->next;
        if(counter == NULL){
            cout << "Invalid pos." << endl;
            return;
        }
        count++;
    }
    if(counter->next == NULL){
        insertAtTail(tail, head, data);
        return;
    }
    temp->next = counter->next;
    counter->next = temp;
}

Node* reverseKKGroup(Node* head, int k){
    // base case
    if(head == NULL){
        return NULL;
    }

    // stpe 1: reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    int count = 0;
    while(count < k && curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // step 2: recursion
    if(forward != NULL){
        head->next = reverseKKGroup(forward, k);
    }

    return prev;
}

void print(const Node* head){
    const Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "-->";
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


    cout << "Enter k-group: ";
    int k;
    cin >> k;
    head = reverseKKGroup(head, k);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    print(head);


    return 0;
}