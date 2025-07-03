#include<iostream>
#include<vector>

using namespace std;

class Node { // Node class represents each element in the queue
    public:
        int data;
        Node* next;

        Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue { //queue class implements a queue using a ll
    Node* head;
    Node* tail;

public:
    Queue() { //constructor initializes the queue
        head = tail = NULL;
    }

    void push(int data) { //push fn adds an element to the end of the queue
        Node* newNode = new Node(data);

        if(empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop() { //remove the front element

        if(empty()) {
            cout << "ll in empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;

    }
    int front() { //return the front element
        if(empty()) {
            cout<< "ll is empty\n";
            return -1;
        }
        return head->data;
    }
    bool empty() { //check if the queue is empty
        return head == NULL;
    }

};

int main() { //main fn
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()) { //print the elements
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;

    return 0;

};