#include<iostream>
#include<vector>
#include<queue>
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

static int idx = -1;
Node* buildTree(vector<int> preorder) {


    idx++;

    if(preorder[idx] == -1) {
        return NULL;
    }


    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void preOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout<<root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<< root->data << " ";
}

void levelOrder(Node* root) {
    queue<Node*> q;

    q.push(root);

    while(q.size() > 0) {
        Node* curr = q.front();
        q.pop();
        
        cout<< curr->data << " ";

        if(curr->left != NULL) {
            q.push(curr->left);
        }
        if(curr->right != NULL) {
            q.push(curr->right);
        }
    }

    cout<< endl;
         
}

int main() {
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
   
    // preOrder(root);
   
    // postorder(root);

    levelOrder(root);
    cout<< endl;

    return 0;

}