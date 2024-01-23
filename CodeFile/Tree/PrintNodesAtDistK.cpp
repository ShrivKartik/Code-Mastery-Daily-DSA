#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int data;
    struct Node* left, *right;
};

struct Node* newNode(int data){
    struct Node* temp = new Node;
    temp -> data = data;
    temp -> left = temp -> right = NULL;
    return temp;
};

void printNodesAtDistanceK(struct Node* root, int k){
    if(root == NULL)
    return;

    if(k == 0){
        cout<<root->data<<" ";
    }

    else{
        printNodesAtDistanceK(root->left , k-1);
        printNodesAtDistanceK(root->right, k-1);
    }
}

int main(){

    struct Node* root = newNode(10);
    root -> left = newNode(11);
    root -> right = newNode(9);
    root -> left -> left = newNode(7);
    root -> left -> right = newNode(12);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(8);

    int k = 2;

    printNodesAtDistanceK(root, k);

}