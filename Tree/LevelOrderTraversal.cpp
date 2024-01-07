#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data){
    Node* temp = new Node;
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

//implementation of Level order traversal

void levelOrderTraversal(Node* root){
    if(root == NULL)
    return;

    queue<Node*> q;

    q.push(root);

    while(q.empty() == false){

        Node* node = q.front();
        cout<<node -> data<<" ";
        q.pop();

        if(node->left != NULL){
            q.push(node->left);
        }

        if(node->right != NULL){
            q.push(node -> right);
        }
    }


}



int main(){
    Node* root = newNode(10);
    root -> left = newNode(20);
    root -> right = newNode(30);
    root -> left -> left = newNode(40);
    root -> left -> right = newNode(50);
    root -> right -> left = newNode(60);
    root -> right -> right = newNode(70);

    cout<<"Level order Traversal of Binary Tree is:";
    levelOrderTraversal(root);

}