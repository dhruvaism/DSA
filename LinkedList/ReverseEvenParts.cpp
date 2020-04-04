#include<iostream>
#include<bits/stdc++.h>

using namespace std;


struct node{
    int data;
    node* next;
};

class Node{

public:
  node* head=NULL;
  node* tail;

  void addNode(int data){

      node *temp = new node;
      temp->data=data;
      temp->next=NULL;

      if(head == NULL){
          head = temp;
          tail = head;
      }
      else{
          tail->next=temp;
          tail=tail->next;

      }
     }

    //printing the list
       void print_list()
         {
             tail=head;
             while(tail->next!=NULL)
               {
                   cout <<tail->data<<"->" ;
                   tail=tail->next;
               }
               cout <<tail->data<<"->" ;
               //tail->next=head;
               cout << endl;

         }

      node* reverseEvenPairs(node* h)
         {
             if(h->next==NULL)
               {
                   return h;
               }
             node* newH = reverseEvenPairs(h->next);

             if(h->data%2 == 0 && newH->data%2 == 0)
               {
         
                      node* ptr = newH->next;
                      newH->next = h;
                      h->next = ptr;


                      return newH;

               }  
            else
            {
                h->next = newH;
                return h;
            }
         }  

       node* reverseEven(node*a, int c) 
          {
                node* newHead = NULL,*prev = NULL,*next,*trav;
                  while(c--)
                    {
                      node * temp = new node;
                      temp->data = a->data;
                      temp->next = NULL;

                      if(newHead==NULL)
                        {
                          newHead = temp;
                          trav = newHead;
                        }
                        else
                        {
                          trav->next = temp;
                          trav=trav->next;
                        }
                        a=a->next;
                        
                    }

                  while(newHead!=NULL)
                    {
                      next = newHead->next;
                      newHead->next = prev;
                      prev = newHead;
                      newHead = next;
                    }  

                  return prev;  
          } 

       node*  reverseEventParts(node* h)
         {

            node* p1 = h;
            node* newHead=NULL;
            node* trav;
            while(p1!=NULL)
              {
                 if(p1->data%2 == 0)
                    {   int c=1;
                        node* p2 = p1;
                        while(p2->next && p2->next->data%2 == 0)
                           {
                                 p2=p2->next;
                                 c++;

                           }
                        cout <<p1->data<<" "<<p2->data<<endl;   

                        if(newHead == NULL)
                           {
                             newHead = reverseEven(p1,c);
                             trav = newHead;
                             while(trav->next)
                               {
                                 trav = trav->next;
                               }
                            
                           }
                          else
                          {
                             trav->next = reverseEven(p1,c);
                              while(trav->next)
                               {
                                 trav = trav->next;
                               }
                            
                          } 

                        
                        p1=p2->next;
                    }
                  else
                    {
                          node* temp = new node;
                          temp->data = p1->data;
                          temp->next = NULL;
                          if(newHead == NULL)
                              {
                                newHead = temp;
                                trav = newHead;
                              }
                             else
                             {
                               trav->next = temp;
                               trav=trav->next;
                             }
                             p1=p1->next;
                                                
                    }
                    


              }

              return newHead;


         }

};


int main()
{
    int n;
    Node a;
    for(int i=0;i<9;i++)
     {
         cin >>n;
         a.addNode(n);
     }

     a.print_list();
     node* newHead = a.reverseEventParts(a.head);

     while(newHead)
       {
           cout <<newHead->data<<"->";
           newHead=newHead->next;
       }

      // a.reverseEventParts();
      // a.print_list(); 

      return 0;
}