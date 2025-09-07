#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* rightMostInLeftSubtree(Node* root){
    Node* ans = NULL;
    while(root != NULL) {
        ans = root;
        root = root->right;
    }
    return ans;
}

Node* leftMostInRightSubtree(Node* root){
    Node* ans = NULL;
    while(root != NULL) {
        ans = root;
        root = root->left;
    }
    return ans;
}

vector<int> getPreSucc(Node* root , int key) {
    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;

    while (curr != NULL) {
        if(key < curr->data) {
            succ = curr;
            curr = curr->left;
        } else if(key > curr->data) {
            pred = curr;
            curr = curr->right;
        } else {
            if(curr->left != NULL) {
                pred = rightMostInLeftSubtree(curr->left);
            }
            if(curr->right != NULL) {
                succ = leftMostInRightSubtree(curr->right);
            }
            break;
        }
    }

    return { pred ? pred->data : -1 , succ ? succ->data : -1 };
}

int main() {
    // Build tree manually
    Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 7;
    vector<int> ans = getPreSucc(root , key);

    cout << "Predecessor: " << ans[0] << endl;
    cout << "Successor: " << ans[1] << endl;

    return 0;
}
