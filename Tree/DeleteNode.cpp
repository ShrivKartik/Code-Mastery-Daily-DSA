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

void inorderTraversal(struct Node* node){

    if(node == NULL)
    return;

    inorderTraversal(node->left);
    cout<<(node->data)<<" ";
    inorderTraversal(node->right);
}

void deleteDeepest(struct Node* root, struct Node* delNode){

    queue<struct Node*> q;
    q.push(root);

    struct Node* temp;

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp = delNode){
            temp = NULL;
            delete(delNode);
            return;

        }


        if(temp->right){
            if(temp->right == delNode){
                temp->right == NULL;
                delete(delNode);
                return;
            }
            else
            q.push(temp->right);
        }

        if(temp->left){
            if(temp->left == delNode){
                temp->left = NULL;
                delete(delNode);
                return;
            }
            else
            q.push(temp->left);
        }

        
    }
}


Node* deletion(struct Node* root, int key){

    if(root == NULL)
    return NULL;

    if(root->left == NULL && root->right == NULL){
        if(root->data == key)
        return NULL;

        else
        return root;
    }

    queue<struct Node*> q;
    q.push(root);

    struct Node* temp;
    struct Node* keyNode = NULL;

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp -> data == key)
        keyNode = temp;

        if(temp->left)
        q.push(temp->left);


        if(temp->right)
        q.push(temp->right);   
    }

    if(keyNode != NULL){
        int x = temp->data;
        deleteDeepest(root, temp);
        keyNode->data = x;
    }
    return root;
}


int main(){

    struct Node* root = newNode(10);
    root -> left = newNode(11);
    root -> right = newNode(9);
    root -> left -> left = newNode(7);
    root -> left -> right = newNode(12);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(8);

    cout<<"Inorder Traversal before deletion: ";
    inorderTraversal(root);

    cout<<endl;

    int key = 11;

    deletion(root,key);

    cout<<"Inorder Traversal after deletion: ";
    inorderTraversal(root);

}