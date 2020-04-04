#include<bits/stdc++.h>
using  namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

class Node{
    public:
      node* root;
      Node(){root=nullptr;}
      void insertNode(int data)
       {
           node* newnode = new node();
           newnode->data=data;
           newnode->left = nullptr;
           newnode->left = nullptr;
          if(root==nullptr)
            {
                root = newnode;
            }
           else
           {
                linker(root,newnode,data);
           }
             
       }

       void linker(node* root,node* newnode ,int data)
         {
             if(!root)
                return;

             queue<node* > q;
             q.push(root);
             while(!q.empty())
               {
                   node* temp = q.front();
                   q.pop();
                   if(temp->left==nullptr)
                      {
                          temp->left=newnode;
                          break;
                      }
                     
                   else
                      q.push(temp->left);
                   if(temp->right==nullptr)
                     {
                          temp->right=newnode;
                          break;
                     }
                   else 
                      q.push(temp->right);         

               }
              while(!q.empty())
                {
                    q.pop();
                } 
              
         }
  
       int usingRecursion(node* root)
         {
               if(!root)
                 return 0;
               int m=usingRecursion(root->left);  
               int n=usingRecursion(root->right);
               if(m>root->data && m>n)
                 return m;
                else if(n>m && n>root->data)
                 return n;
                else 
                 return root->data;   
             
         }  

       void usingLevelOrdering(node* root)
         {
             int max=-5;
             if(!root)
               return;
             queue<node* > q;
             q.push(root);
             while(!q.empty())
              {
                  node* temp = q.front();
                  q.pop();
                  if(temp->data > max)
                    max = temp->data;
                  if(temp->left)
                     q.push(temp->left);
                  if(temp->right)
                     q.push(temp->right);     

              } 

            cout <<"Max: "<<max<<endl;
         }  

       void preorder(node* root)
         {
             if(root)
               {
                   cout <<root->data<<" ";
                   preorder(root->left);
                   preorder(root->right); 
               }
         }  

        node* linkedListConsistOfLeafs(node* head,node *trav,node* root)
          {
            if(!root)
               return nullptr;
            if(!root->left && !root->right)
              {
                return root;
              }
              
            node* temp=linkedListConsistOfLeafs(head,trav,root->left);
            node* temp1=temp;
            while(temp1->right)
              temp1=temp1->right;
            temp1->right = linkedListConsistOfLeafs(head,trav,root->right);
            
            

           return temp;
          } 
 

};


int main()
 {

     Node tree;
     int n;
     for(int i=0;i<10;i++)
       {
           cin >>n;
           tree.insertNode(n);
       }
     tree.preorder(tree.root); 
      tree.usingLevelOrdering(tree.root);
      cout <<tree.usingRecursion(tree.root)<<endl;

      
      node* x=nullptr,*y;
      node* head = tree.linkedListConsistOfLeafs(x,y,tree.root);
      while(head)
        {
          cout <<head->data<<" ";
          head=head->right;
        }
     
     return 0;
 }