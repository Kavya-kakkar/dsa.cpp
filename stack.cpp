<<<<<<< HEAD
#include<iostream>
#include<vector>
using namespace std;    

class Stack {
    vector<int> v;

public:
    
    void push(int val) {
        v.push_back(val);
    }

    void pop() {
        v.pop_back();
    }

    int top() {
        return v[v.size()-1];
    }

    bool empty() {
        return v.size() == 0;
    }
};

int main() {
    Stack s;
    s.push(20);
    s.push(80);
    s.push(90);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
=======
#include<iostream>
#include<vector>
using namespace std;    

class Stack {
    vector<int> v;

public:
    
    void push(int val) {
        v.push_back(val);
    }

    void pop() {
        v.pop_back();
    }

    int top() {
        return v[v.size()-1];
    }

    bool empty() {
        return v.size() == 0;
    }
};

int main() {
    Stack s;
    s.push(20);
    s.push(80);
    s.push(90);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
>>>>>>> eeefa3de8135b9eee21314f96d4df2961a560dca
}