#include <iostream>
using namespace std;

class Node{
    public:
        Node* prev;
        int data;
        Node* next;
    
    // node constructor
    Node(int data){
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }

    // node destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory with data: " << value << " deleted" << endl;
    }
};

void insertAtHead(Node* &head, Node* &tail, int data){
    Node* temp = new Node(data);

    // empty list
    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int data){
    Node* temp = new Node(data);

    // empty list
    if(tail == NULL){
        tail = temp;
        head = temp;
    }
    else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtMiddle(Node* &head, Node* &tail, int data, int pos){
    // empty list
    if(head == NULL && tail == NULL){
        insertAtHead(head, tail, data);
        return;
    }
    // if pos == 1 -> it means insertion taking place at head;
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
            cout << "Position out of bounds!" << endl;
            return;
        }
        count++;
    }

    // if pos is pointing to last node i.e. it's next is NULL call insertAtTail
    if(counter->next == NULL){
        insertAtTail(tail, head, data);
        return;
    }

    // for in between insertion
    temp->next = counter->next;
    counter->next->prev = temp;
    counter->next = temp;
    temp->prev = counter;
}

void deleteNode(Node* &head, Node* &tail, int pos){
    if(head == NULL && tail == NULL){
        cout << "List is empty" << endl;
        return;
    }
    // deleting first node
    if(pos == 1){
        Node* temp = head;
        if(temp->next != NULL){
            temp->next->prev = NULL;
        }
        head = temp->next;
        temp->next = NULL;

        delete temp;
    }
    else{
        Node* current = head;
        Node* prev = NULL;

        int count = 1;
        while(count < pos){
            prev = current;
            current = current->next;
            if(current == NULL){
                cout << "Deletion position out of bounds!" << endl;
                return;
            }
            count++;
        }
        if(current->next == NULL){
            tail = prev;
            prev->next = NULL;
            current->prev = NULL;

            delete current;
        }
        else{
            current->next->prev = prev;
            prev->next = current->next;
            current->next = NULL;
            current->prev = NULL;
        }

        delete current;
    }
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
    // Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    insertAtTail(tail, head, 40);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    insertAtMiddle(head, tail, 50, 1);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    insertAtMiddle(head, tail, 51, 1);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    insertAtMiddle(head, tail, 52, 3);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    deleteNode(head, tail, 2);
    cout << "delete head: " << head->data << endl;
    cout << "delete tail: " << tail->data << endl;
    print(head);
    deleteNode(head, tail, 1);
    cout << "delete head: " << head->data << endl;
    cout << "delete tail: " << tail->data << endl;
    print(head);
    deleteNode(head, tail, 4);
    cout << "delete head: " << head->data << endl;
    cout << "delete tail: " << tail->data << endl;
    print(head);
    deleteNode(head, tail, 40);
    cout << "delete head: " << head->data << endl;
    cout << "delete tail: " << tail->data << endl;
    print(head);


    // freeing all memory after usage
    Node* current = head;
    while(current != NULL){
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}