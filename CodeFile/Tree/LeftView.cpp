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

int maxLevel = 0;

void printLeft(struct Node* root, int level){
    if(root == NULL)
    return;

     if(maxLevel < level){
        cout<<(root->data)<<" ";
        maxLevel = level;
     }

     printLeft(root->left, level+1);
     printLeft(root->right, level+1);
}

void printLeftView(struct Node* root){
    printLeft(root,1);
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
    printLeftView(root);

    return 0;

}
