#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

void inOrder(node* root)
  {
      if(root)
       {
           inOrder(root->left);
           cout<<root->data<<" ";
           inOrder(root->right);
       }
  }

int minDepth(node *root) 
{ 
    
    
    if (root == NULL) 
        return 0; 
  
    
    if (root->left == NULL && root->right == NULL) 
    return 1; 
  

    if (!root->left) 
    return minDepth(root->right) + 1; 
  
    if (!root->right) 
    return minDepth(root->left) + 1; 

    //check with this
    return min(minDepth(root->left), minDepth(root->right)); 
    //if no
    //return min(minDepth(root->left), minDepth(root->right))+1; 
} 
  

void buildTree(int* in, int* level,int n,int* index)
 {
     struct node* root = new node;
     root->data=level[0];
     root->left=NULL;
     root->right=NULL;
     struct node* ptr=root;

     for(int i=1;i<n;i++)
      {
          struct node* newNode = new node;
          newNode->data=level[i];
          newNode->left=NULL;
          newNode->right=NULL;
             while(1){
                int j=index[ptr->data];
                while(j>=0 && level[i]!=in[j])
                 {
                     j--;
                 }
                if(j==-1)
                 {
                      if(ptr->right==NULL)
                      {
                         ptr->right=newNode;
                         ptr=root;
                         break;
                      }
                     if(ptr->right)
                      ptr=ptr->right;
                    
                 }
                else  
                 {
                     if(ptr->left==NULL)
                      {
                         ptr->left=newNode;
                         ptr=root;
                         break;
                      }
                     if(ptr->left)
                      ptr=ptr->left;
                 }
             }

            
      }

      //inOrder(root);
      
      cout<<endl<<minDepth(root)<<endl;
 }

 


int main()
 {
     int n=6;
     int in[]={4,3,6,5,2,7};
     int level[]={2,3,7,4,5,6};

     int index[6]={-1};
     for(int i=0;i<6;i++)
      {
          index[in[i]]=i;
      }

     buildTree(in,level,n,index);

    
     
 }