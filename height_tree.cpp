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

int height(Node* root) {  //height of tree
    if(root == NULL) {
        return 0;
    }
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    return max(leftHt,rightHt) + 1;
}

int count(Node* root) { //count of nodes
    if(root == NULL) {
        return 0;
    }
    int leftCnt = count(root->left);
    int rightCnt = count(root->right);
    return(leftCnt+rightCnt) + 1;
}

int sum(Node* root) { //sum of nodes
    if(root == NULL) {
        return 0;
    }
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    return (leftSum + rightSum + root->data);
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);

    // cout<< " height : " << height(root) << endl;
    // cout<< " count : " << count(root) << endl;
    cout << "sum : " << sum(root) << endl;
    return 0;
};


