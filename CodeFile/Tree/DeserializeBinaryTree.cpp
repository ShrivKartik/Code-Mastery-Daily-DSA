#include<iostream>
#include<vector>
using namespace std;

struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      data=k;
      left=right=NULL;
  }
};

void inorder(struct Node* node){

    if(node == NULL)
    return;

    inorder(node->left);
    cout<<(node->data)<<" ";
    inorder(node->right);
}

const int EMPTY = -1;
struct Node* deserialize(vector<int>& arr, int &index){
    if(index == arr.size()){
        return NULL;
    }

    int val = arr[index];
    index++;

    if(val == EMPTY){
        return NULL;
    }

    struct Node* root = new Node(val);
    root->left = deserialize(arr,index);
    root->right = deserialize(arr,index);

    return root;

}

int main(){
    vector<int> arr{10 ,5 ,-1 ,-1 ,30 ,15 ,-1 ,-1 ,20 ,-1 ,-1};
    int index = 0;
    struct Node* new_root = deserialize(arr,index);
    inorder(new_root);
    
    
}