#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
  {
      int data;
      node * next;
      node * rand;
  };

class Node
{
    public:
       node *head,*tail, *rand;

     Node()
       {
           head=NULL;
           tail=NULL;
           rand=NULL;
       }
       //adding node to end
      void add_node(int d)
        {
            node *temp = new node;
            temp->data = d;
            temp->next=NULL;

            if(head==NULL)
              {
                  head=temp;
                  tail=temp;
              }
              else
              {
                  tail->next=temp;
                  tail=tail->next;
              }


        }

        //printing the list
       void print_list()
         {
             tail=head;
             while(tail!=NULL)
               {
                   cout <<tail->data<<"->" ;
                   tail=tail->next;
               }

              cout<<endl;
               tail=head;
             while(tail!=NULL)
               {
                   cout <<"|  ";
                   tail=tail->next;
               }

                cout<<endl;
               tail=head;
             while(tail!=NULL)
               {
                   cout <<"v  ";
                   tail=tail->next;
               }

                cout<<endl;
               tail=head;
             while(tail!=NULL)
               {
                   cout <<tail->rand->data<<"  ";
                   tail=tail->next;
               }
             
         } 
             //NO EXTRA SPACE
            node * clone1(node *a){

                node *ptr,*temp,*next;
                ptr = a;
                while(ptr)
                  {

                     temp = ptr->next;
                     node * n = new node;
                     n->data = ptr->data;
                     ptr->next=n;
                     ptr->next->next=temp;
                     ptr=ptr->next->next;


                  }
                  ptr=a;
                  while (ptr)
                  {
                  ptr->next->rand = ptr->rand->next;
                  ptr=ptr->next->next;
                  }
                  ptr=head;
                  while(ptr->next)
                    {
                        ptr=ptr->next;
                    }
                  node *po = ptr;  
                  a=a->next;
                  ptr =a;
                  while(ptr!=po)
                    {
                        ptr->next=ptr->next->next;
                        ptr=ptr->next;
                    }
                  


               return a;
            }


             //IT WILL TAKE EXTRA SPACE
            node* clone(node *a){

                unordered_map<node*, node*> hash;

                node * ptr,*newhead=NULL,*trav,*rand,*t,*r;

                ptr = a;
                while (ptr)
                {
                    node* temp = new node;
                    temp->data = ptr->data;
                    temp->next = NULL;
                    temp->rand = NULL;
                    hash.insert({ptr,temp});
                    ptr=ptr->next;
                }
                ptr = a;
                while (ptr)
                {   
                    t = hash.at(ptr);
                    r = hash.at(ptr->rand);
                    t->next = NULL;
                    t->rand=r;
                   
                    if(newhead==NULL) 
                      {
                          newhead = t;
                          trav = newhead;
                          
                          
                      }
                      else
                      {
                        trav->next = ptr;
                        trav = trav->next;
                      }
                      ptr = ptr->next;
                      
                }
                
                return newhead;

            } 




};


int main(){

    Node a,b;

    //taking input of data and Calling Add_node() function
       int n,m;
       for(int i=0;i<4;i++)
         {
           scanf("%d",&n);
           a.add_node(n);
         }
       
         a.head->rand = a.head->next->next;
         a.head->next->rand = a.head;
         a.head->next->next->rand = a.head->next->next;
         a.head->next->next->next->rand = a.head->next;

           a.print_list();
           cout <<endl;

           node* node = a.clone1(a.head);
           b.head = node;

          b.print_list();



}         



