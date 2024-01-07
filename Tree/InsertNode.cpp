#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    struct Node* left, *right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

void inorderTraversal(struct Node* node){

    if(node == NULL)
    return;

    inorderTraversal(node->left);
    cout<<(node->data)<<" ";
    inorderTraversal(node->right);
}

void insertNode(struct Node* root, int key){
    if(root == NULL)
    return;

    queue<Node*> q;
    q.push(root);

    while(q.empty() == false){
        struct Node* temp = q.front();
        q.pop();

        if(temp->left == NULL){
            temp->left = new Node(key); 
            break;
        }
        else{
            q.push(temp -> left);
        }

        if(temp->right == NULL){
            temp->right = new Node(key); 
            break;
        }
        else{
            q.push(temp -> right);
        }
    }
}


int main(){
    struct Node* node = new Node(10);
    node -> left = new Node(20);
    node -> right = new Node(30);
    node -> left -> left = new Node(40);
    node -> right -> left = new Node(50);
    node -> right -> right = new Node(60);

    cout<<"Inorder traversal before insertion: ";
    inorderTraversal(node);

    cout<<endl;

    insertNode(node,-10);

    cout<<"Inorder traversal after insertion: ";
    inorderTraversal(node);








}