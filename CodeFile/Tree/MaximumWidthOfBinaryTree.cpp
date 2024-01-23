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

int maxWidth(struct Node* root){
    if(root == NULL)
    return 0;

    queue<struct Node*>q;

    q.push(root);

    int res = 0;

    while(!q.empty()){

        int count = q.size();

        res = max(res, count);

        for(int i=0; i<count; i++){
            struct Node* temp = q.front();
            q.pop();
            if(temp->left)
            q.push(temp->left);

            if(temp->right)
            q.push(temp->right);
        }
    }

    return res;

}

int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->left=new Node(60);
	
	cout<<maxWidth(root);
}