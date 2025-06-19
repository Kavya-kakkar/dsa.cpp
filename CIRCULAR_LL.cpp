#include<iostream>
using namespace std;

class Node { //node class create for ll
public:
    
    int data;
    Node* next;


    Node(int val) {
        data = val;
        next = NULL;
    }

};

class CicularList { //circular ll class started
    Node* head;
    Node* tail;

public:
    CicularList() {
        head = tail = NULL;
    }

    void insertAtHead(int val) { // insertat head fucntion
        Node* newNode = new Node(val);

        if(tail == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void print () { // print fn for the above
        if(head == NULL) return;

        cout << head->data << "->";
        Node* temp = head->next;

        while(temp != head) {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << temp->data << endl;
    }

    void insertAtTail(int val) { // insert at tail fn 
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtHead() { // delete at head fn 
        if(head == NULL) return;
        else if(head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
    }

    void deleteAtTail() { // delete t tail fn 
        if(head == NULL) return;
        else if(head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = tail;
            Node* prev = head;
            while(prev->next != tail) {
                prev = prev->next;
            }

            tail = prev;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
    }
};

int main() { // main fn for print
    CicularList Cll;

    // Cll.insertAtHead(1); 
    // Cll.insertAtHead(2);
    // Cll.insertAtHead(3);

    Cll.insertAtTail(1);
    Cll.insertAtTail(2);
    Cll.insertAtTail(3);


    Cll.deleteAtTail();

    Cll.print();

    return 0;

}