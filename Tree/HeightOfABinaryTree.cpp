#include<iostream>
#include<algorithm>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
    Node(int k){
        this->data = k;
        left = right = NULL;
    }
};

int height(Node* root){
    if(root == NULL)
    return 0;

    return max(height(root->left) , height(root->right))+ 1;
}

int main(){
    Node* root = new Node(30);
    root->left = new Node(40);
    root->left->left = new Node(10);
    root->left->left->left = new Node(90);
    root->left->left->left->left = new Node(80);
    root->left->left->left->left->left = new Node(50);
    root->right = new Node(60);

    cout<<"Height of a given Binary Tree is: ";
    cout<<height(root);
}