#include<bits/stdc++.h>
using  namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};

node* newNode(int item, node* parent) 
{ 
    node* temp = new node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    temp->parent = parent; 
    return temp; 
} 

void preorder(node* root)
 {
     if(root)
      {
          cout<<root->data<<" ";
          preorder(root->left);
          preorder(root->right);
      }
 }

 node* find(node* pointer,int l)
  {
      int prevL=l;
      
      while(pointer->parent && !pointer->right)
       {
          l--;
          pointer=pointer->parent;
       }
       while(pointer && pointer->right && prevL!=l)
        {
            pointer=pointer->right;
            l++;
            
        }
        
        return pointer;
  }


 node* findRight(node* root,node* pointer,int l)
  {
      if(!root)
        return NULL;
      if(root==pointer)
        {
            return find(pointer,l);
        }  
        node* temp;
       if(root->left)
         {
             l++;
             temp = findRight(root->left,pointer,l); 
         }
      return temp;
  }

int main()
 {
     node* root = newNode(1, NULL);                                               
    root->left = newNode(2, root); 
    root->right = newNode(3, root); 
    root->left->left = newNode(4, root->left); 
    root->left->right = newNode(6, root->left); 
    root->left->left->left = newNode(7, root->left->left); 
    root->left->left->left->left = newNode(10, root->left->left->left); 
    root->left->right->right = newNode(9, root->left->right); 
    root->right->right = newNode(5, root->right); 
    root->right->right->right = newNode(8, root->right->right); 
    root->right->right->right->right = newNode(12, root->right->right->right);

   // preorder(root);

    node* right=findRight(root,root->left->left->left->left, 0);
    cout<<right->data<<endl;

     
     
 }