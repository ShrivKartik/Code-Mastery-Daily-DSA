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

int getMax(struct Node* root){
    if(root == NULL)
    return INT_MIN;

    return max(root->data, max(getMax(root->left) , getMax(root->right)));
}

int main(){

    struct Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(60);

    cout<<"Maximum in Binary Tree is: ";
    cout<<getMax(root);

    return 0;

}