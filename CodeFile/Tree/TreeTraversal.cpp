#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left, *right;

    Node(int data){
        this->data = data;
        left = right = NULL; 
    }
};

// implementing Preorder Traversal

void preorderTraversal(struct Node* node){

    if(node == NULL)
    return;

    cout<<(node->data)<<" ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

//implementing Postorder Traversal

void postorderTraversal(struct Node* node){

    if(node == NULL)
    return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout<<(node->data)<<" ";   
}

void inorderTraversal(struct Node* node){

    if(node == NULL)
    return;

    inorderTraversal(node->left);
    cout<<(node->data)<<" ";
    inorderTraversal(node->right);
}


int main(){
    struct Node* node = new Node(10);
    node -> left = new Node(20);
    node -> right = new Node(30);
    node -> left -> left = new Node(40);
    node -> left -> right = new Node(50);

    cout<<"Preorder Traversal of given Binary Tree is:";
    preorderTraversal(node);
    cout<<endl;

    cout<<"Postorder Traversal of given Binary Tree is:";
    postorderTraversal(node);
    cout<<endl;

    cout<<"Inorder Traversal of given Binary Tree is:";
    inorderTraversal(node);
    cout<<endl;
}