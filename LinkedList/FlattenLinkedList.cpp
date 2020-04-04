#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* next;
    node* down;
};

class Node {
    public:
       node* head;
       node * tail;

    Node(){
        head = NULL;
        tail = NULL;
    }  

    void add_down_node(node* head,int no_child_node)
       {
            node* trav;
            trav = head;
            int n;
            for(int i=0;i<no_child_node;i++)
                {
                    node * temp = new node;
                    cin >>n;
                    temp->data=n;
                    temp->next=NULL;
                    temp->down=NULL;
                    trav->down=temp;
                    trav=trav->down;

                }

       }

    void add_main_node(int data, int no_child_node)
      {
          node * temp = new node;
          
          temp->data=data;
          temp->next=NULL;
          temp->down=NULL;

          
          add_down_node(temp,no_child_node);
           
          if(head == NULL)
             {
                 head=temp;
                 tail = head;
             }
           else
           {
               tail->next=temp;
               tail=tail->next;
           }
             



      }

      node* merge( node* a, node* b ) 
          { 
               // If first list is empty, the second list is result 
             if (a == NULL) 
                return b; 
  
               // If second list is empty, the second list is result 
             if (b == NULL) 
                return a; 
  
              // Compare the data members of head nodes of both lists 
              // and put the smaller one in result 
            node* result; 
            if (a->data < b->data) 
                { 
                    result = a; 
                    result->down = merge( a->down, b ); 
                } 
             else
                { 
                  result = b; 
                  result->down = merge( a, b->down ); 
                } 
  
             return result; 
      } 

      node* flatten (node* root) 
          { 
               // Base cases 
              if (root == NULL || root->next == NULL) 
                   return root; 
  
               // Merge this list with the list on right side 
            return merge( root, flatten(root->next) ); 
          } 

      void print_list()
        {
            node *travmain,*travdown;
            travmain = head;
            
            while(travmain)
              {
                  travdown  = travmain;
                  while (travdown)
                  {
                      cout<<travdown->data<<"->";
                      travdown=travdown->down;
                  }
                  cout <<endl;
                  travmain=travmain->next;

              }
        }

};


int main(){
    Node a;
    int n,m;
    for(int i=0;i<3;i++)
      {
          cout <<"Enter main node:";
          cin >>n;
          cout <<"Enter child nodes:";
          cin >>m;
          a.add_main_node(n,m);
      }

      a.print_list();

      node *head = a.flatten(a.head);
      
      while(head)
        {
            cout <<head->data<<"->";
            head=head->down;
        }
}