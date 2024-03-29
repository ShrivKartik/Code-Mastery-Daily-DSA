#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

bool isCSum(struct Node *root){
    if(root == NULL)
    return true;

    if(root->left == NULL && root->right == NULL)
    return true;

    int sum = 0;

    if(root->left)
    sum+= root->left->key;

    if(root->right)
    sum+= root->right->key;

    return (root->key == sum) && (isCSum(root->left)) && (isCSum(root->left));
}



int main() {
	
	Node *root=new Node(20);
	root->left=new Node(8);
	root->right=new Node(12);
	root->right->left=new Node(3);
	root->right->right=new Node(9);
	
	cout<<isCSum(root);
}