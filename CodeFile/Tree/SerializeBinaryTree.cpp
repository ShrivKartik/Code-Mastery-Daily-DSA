#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    struct Node* left, *right;

    Node(int k){
        this->data = k;
        left = right = NULL;
    }
};

const int EMPTY = -1;
void serialize(struct Node* root, vector<int>& arr){
    if(root == NULL){
        arr.push_back(EMPTY);
        return;
    }

    arr.push_back(root->data);
    serialize(root->left,arr);
    serialize(root->right,arr);
}

int main(){
    Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(30);
	root->right->left=new Node(15);
	root->right->right=new Node(20);

    vector<int> arr;

    serialize(root,arr);

    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}