#include<iostream>
using namespace std;

class Node { //node class to create a node of the ll
    public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List{ //list class to implement the ll
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void push_front(int val) { //function to insert the node in the front of the ll
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;

        } else {
            newNode->next = head;
            head = newNode;
        }
     }
    void push_back(int val) { //funtion to insert the node in the back of the ll
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;

        }else {
            tail->next = newNode;
            tail = newNode;
        }
     
    }
    void pop_front() { //function to delete the node from the front of the ll
        if(head == NULL) {
            cout<<"ll is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void pop_back() { // function to delete the node from the back of the ll
        if(head == NULL) {
            cout<<"ll is empty\n";
            return;
        }

        Node* temp = head;
        while(temp->next !=tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    void printll() { // function to print the linked list 
        Node* temp = head;

        while(temp != NULL){
            cout << temp->data << "  " ;
            temp = temp->next;

        }
        cout << endl;
    }
   
};

int main() { //main function to test the ll implemenatation
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);
    ll.pop_front();
    ll.printll();
    ll.pop_back();
    ll.printll();
    return 0;
}