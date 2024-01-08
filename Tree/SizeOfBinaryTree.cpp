#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left, *right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

int getSize(struct Node* root){

    if(root == NULL)
    return 0;

    return getSize(root->left) + getSize(root->right) + 1;

}

int main(){

    struct Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(60);

    cout<<"Size of Binary Tree: ";
    cout<<getSize(root);

    return 0;
}