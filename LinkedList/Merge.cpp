#include<iostream>
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

        node* pair_swap(node *head)
           {
               node* temp;
                 
               if(head!=NULL && head->next!=NULL)
                 {
                     return NULL;
                 }  
               //Reverse First pair
               temp=head->next; 
               head->next=temp->next;
               temp->next=head;
               head = temp;

               //Recursive call for Rest

               head->next->next = pair_swap(head->next->next);

               return temp;

              
           }

        // node* getKthnode(node* head, int k)
        //     {
        //       int i;
        //       node *kth;

        //       if(head==NULL)
        //          return head;
                

        //       for(i=0,kth=head ;kth && i<k;i++,kth=kth->next);
        //       if(i==k && kth!=NULL)
        //          return kth;
             
        //       return head->next;

        //     }

        // int hasKnodes(node *head, int k)
        //    {
        //      int i;
        //      for( i=0;head && i<k;i++,head=head->next);
        //      if(i==k)
        //        return 1;
             
        //      return 0;
               
        //    }


        // void reverse_k_block(int k)
        //    {
        //      node *temp,*newhead,*curr,*next;

        //      curr = head;

        //      if(hasKnodes(curr,k-1))
        //        {
        //           newhead = getKthnode(curr,k-1);
        //        }
        //      else
        //        {
        //           newhead = head;
        //        }

        //      while(curr && hasKnodes(curr,k))
        //        {
                    
        //             temp = getKthnode(curr,k);
        //             int i=0;
        //             while (i<k)
        //             {
        //               next = curr->next;
        //               curr->next=temp;
        //               temp = curr;
        //               curr = next;
        //               i++;
        //             }
                    
        //        }

        //        int i=1;
        //        while(i<5)
        //          {
        //            cout <<newhead->data<<"->";
        //            newhead = newhead->next; 
        //            i++;
        //          }
        //       // cout <<newhead->data<<"->"<<newhead->next->data<<endl;
               
               
        //    }   

        node * reverse_k_block(int k, node *head)
           {
             node * curr = head;
             node* prev = NULL, * next = NULL;
             int count = 0;

             while (curr && count < k)
             {
               
               next=curr->next;
               curr->next = prev;
               prev = curr;
               curr = next;
               count++;

             }
             
             if(next!=NULL)
                {
                  head->next = reverse_k_block(k,next);
                }

               return prev;

           }


     
};  

node* merge_recursive(node *a, node *b)
   {
       node *result = NULL;
       if(a==NULL)
         {
             return b;
         }
        if(b== NULL)
          {
              return a;
          } 
        if(a->data<=b->data)
           {
               result = a;
               result->next = merge_recursive(a->next,b);
           }  
           else
           {
               result = b;
               result->next = merge_recursive(b->next,a);
           }

          return result; 
   }

void merge(Node a, Node b)
   {

     node *p1,*p2,*np;
     p1=a.head;
     p2=b.head;
     node *nhead=NULL;

     while(p1!=NULL && p2!=NULL)
        {
            if(p1->data<=p2->data)
                {
                      if(nhead==NULL)
                          {
                              nhead=p1;
                              np=nhead;
                          }
                        else
                        {
                            np->next=p1;
                            np=np->next;
                            
                        }
                          
                       p1=p1->next;

                }
                else
                {
                     if(nhead==NULL)
                          {
                              nhead=p2;
                              np=nhead;
                          }
                        else
                        {
                            np->next=p2;
                            np=np->next;
                          
                        }
                  p2=p2->next; 
                }


              
              
                
        }

      if(p1!=NULL)
      {
          np->next=p1;
          np=np->next;
          p1=p1->next;

      }
      if(p2!=NULL)
      {
         np->next=p2;
         np=np->next;
         p2=p2->next;
      }

        cout <<np->data<<endl;

      while (nhead!=NULL)
      {
          cout <<nhead->data<<"->" ;
          nhead=nhead->next;
      }
        

   }



int main(){

    Node a,b;

    //taking input of data and Calling Add_node() function
       int n,m;
       for(int i=0;i<4;i++)
         {
           scanf("%d",&n);
           a.add_node(n);
         }
        // for(int i=0;i<5;i++)
        //  {
        //    scanf("%d",&n);
        //    b.add_node(n);
        //  } 

        //  //merge(a,b);
        //  node * nhead = merge_recursive(a.head,b.head);
        //  while(nhead!=NULL)
        //    {
        //        cout <<nhead->data<<"->";
        //        nhead=nhead->next;
        //    }

         a.print_list();
        //  node *head = a.pair_swap(a.head);

        //  while (head!=NULL)
        //  {
        //      cout <<head->data<<"->";
        //      head=head->next;
        //  }
       node * newHead =  a.reverse_k_block(3,a.head);

       while (newHead)
       {
         cout <<newHead->data<<"->";
         newHead=newHead->next;
       }
       


    return 0;
}