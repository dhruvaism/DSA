#include<bits/stdc++.h>
using namespace std;

struct node
  {
      int data;
      node * next;
  };

class Node
{
    public:
       node *head,*tail;

     Node()
       {
           head=NULL;
           tail=NULL;
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

       node * first_node_cycle()
         {
           node *slow = head;
           node *fast = head;
           

           while(fast && fast->next)
             {
              
                  fast=fast->next->next;
                  slow = slow->next;
                  if(fast == slow)
                    {
                      break;
                    }
                 

             }
           
           slow = head;
           while(slow!=fast)
              {
                  
                    slow=slow->next;
                    fast=fast->next;
                  
                    

              }
             return slow; 


         }

       bool check_cycle()
          {
              unordered_map <node*, int> umap;
              node *t=head;
              while(t!=NULL)
                {
                  if(umap.find(t) == umap.end())
                     {
                         umap[t]++;
                         t=t->next;
                     }
                    else
                    {
                      return true;
                    }

                }
               return false;

           }

           void reverse() {
             node* curr,* prev,*next;
             prev = NULL;
             curr = head;
             while(curr!=NULL)
                {
                  next=curr->next;
                  curr->next = prev;
                  prev = curr;
                  curr = next;

                 }

           } 

};


int main()
 {
     //creating Object of Node class
       Node a;

     //taking input of data and Calling Add_node() function
       int n,m;
       for(int i=0;i<5;i++)
         {
           scanf("%d",&n);
           a.add_node(n);
         }
       //   a.tail->next=a.head;
       // if(a.check_cycle())
       //    {
       //        cout <<"Cycle found"<<endl;
       //    }
       //    else
       //    {
       //        cout <<" Cycle Not Found"<<endl;
       //    }

       a.tail->next  = a.head->next->next;

       if(a.check_cycle())
         cout <<"found"<<endl;

       cout <<a.first_node_cycle()->data<<endl; 

return 0;
 }
