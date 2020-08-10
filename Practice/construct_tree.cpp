#include<iostream>
using namespace std;

int n=5;
int in[]={6,2,4,3,10};
int post[]={6,4,2,10,3};

struct node{
    int data;
    struct node* left;
    struct node* right;
};

int searchIndex(int data){
    for(int i=0;i<n;i++){
        if(in[i]==data){
            return i;
        }
    }
    return -1;
}

struct node* constructTree(int inStart,int inEnd){
      
      struct node* root;
      static int preIndex = n-1;
      
      if(inEnd<inStart)
       return NULL;

      root = new node();
      root->data = post[preIndex--];

      int nextIndex = searchIndex(root->data); 

      root->right = constructTree(nextIndex+1,inEnd);
      root->left = constructTree(inStart,nextIndex-1);

      return root;
}


void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){


    

    node* root = constructTree(0,n-1);
    inorder(root);
    cout<<endl;

    return 0;
}