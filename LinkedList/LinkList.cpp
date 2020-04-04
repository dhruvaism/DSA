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

      //ODD or Even length

      void even_or_odd(){
        node* p =head;

        while (p!=NULL)
        {
          if(p->next==NULL)
              {
                cout <<"Odd"<<endl;
                break;
              }
          else if(p->next->next==NULL)
             {
               cout <<"Even"<<endl;
                break;
             } 
             else
             {
               p=p->next->next;
             }
             
              
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

      //dectect loop and count no of node in loop
       void detect_loop()
         {
             node *s=head;
             node *f=head;
             while(s!=NULL && f!=NULL && f->next!=NULL)
               {
                   s=s->next;
                   f=f->next->next;
                   if(s==f)
                     {
                      cout<<"\nLoop found" ;
                      break;
                     }
               }
         }

       //remove kth node
       void remove(int k)
         {
           int count=0;
           tail=head;
           node * prev=NULL;
           while(tail!=NULL)
             {
                count++;
               if(count==k)
                 {
                   prev->next=tail->next;
                   count=0;
                 }
              if(count!=0)
                 {
                   prev=tail;
                 }
               tail=tail->next;

             }

         }
         //Segreagate
         void segregate()
           {
             node* prev=NULL,* curr=head,*end=head,*new_end;
             while(end->next!=NULL)
               {
                 end=end->next;
               }
             new_end=end;

             while((curr->data%2)!=0 && curr!=end)
              {
                 new_end->next=curr;
                 curr=curr->next;
                 new_end->next->next=NULL;
                 new_end=new_end->next;

              }


              if(curr->data%2 == 0)
                {
                  head=curr;
                  while(curr!=end)
                    {
                      if(curr->data%2 == 0)
                        {
                          prev=curr;
                          curr=curr->next;
                        }
                        else
                        {
                          prev->next=curr->next;
                          new_end->next=curr;
                          new_end->next->next=NULL;
                          new_end=new_end->next;

                          curr=prev->next;

                        }

                    }

                }
                else
                {
                  prev=curr;
                }

               if(end!=new_end)
                 {
                   prev->next=end->next;
                   end->next=NULL;
                   new_end->next=end;
                 }

           }
         //Remove duplicates
         void remove_duplicate()
           {
             node *curr1,*prev2,*curr2;
             curr1=head;
             while(curr1->next!=NULL)
               {
                  prev2=NULL;
                  curr2=curr1;
                  while(curr2!=NULL)
                    {
                         if(curr1->data == curr2->data && curr1!=curr2)
                            {
                               prev2->next=curr2->next;
                            }
                            else
                            {
                              prev2=curr2;
                            }
                            curr2=curr2->next;




                    }
                    curr1=curr1->next;
               }
           }
         //Pairwise swap
         void swap_pair()
           {
               node *p=head,*temp,*q;
               head=head->next;


                while(1)
                {
                     q=p->next;
                     temp=q->next;
                     q->next=p;
                      if(temp==NULL || temp->next==NULL)
                         {
                           p->next=NULL;
                           break;
                         }
                     p->next=temp->next;
                     p=temp;

                }

           }
           //nth node finder
           void nthNode(int n)
           {
             node *end=head,*nth=head;
             int c=0;

             while(end!=NULL)
                {
                  if(c == n)
                    {
                      nth=nth->next;
                    }
                    else
                    {
                      c++;
                    }

                  end=end->next;

                }
              cout <<nth->data;


           }


          //Reverse using recursion
          node * recursive_reverse(node *h)
            {
              if(h->next == NULL)
                {
                   return h;
                }

               node * newh = recursive_reverse(h->next);
               h->next->next = h;
               h->next = NULL; 

               return newh;

            }

        node *zigZack(node* head)
{
 // your code goes here
 node* p = head;
 while(p->next && p->next->next && p)
    {
      node* first = p;
      node* second = p->next;
      node* third = p->next->next;
    if((first->data > second->data)&&(first->data > third->data))
       {
           first->next = third;
           second->next = first;
           p=second;
           
       }
     else if((second->data > first->data)&&(second->data > third->data))
       {
           p=first;
       }
      else
       {
           first->next = third;
           second->next = third->next;
           third->next = second;
           p=first;
       }  
       p=p->next->next;
      
    }
         
 return head;

}





};

void pairs(int p, Node a, Node b)
 {
   a.tail=a.head;
    while(a.tail!=NULL)
      {
        b.tail=b.head;
        while(b.tail!=NULL)
          {
            if((a.tail->data+b.tail->data)==p)
              {
                cout <<"("<<a.tail->data<<","<<b.tail->data<<")\n" ;
              }
              b.tail=b.tail->next;
          }
          a.tail=a.tail->next;
      }



 }





int main()
 {
     //creating Object of Node class
       Node a,b;

     //taking input of data and Calling Add_node() function
       int n,m;
       for(int i=0;i<4;i++)
         {
           scanf("%d",&n);
           a.add_node(n);
         }

      //  for(int i=0;i<5;i++)
      //    {
      //      scanf("%d",&m);
      //      b.add_node(m);
      //    }



     //calling print function
      //  a.print_list();
       // b.print_list();

    //dectect loop call
    //  a.detect_loop();

   //No of pairs
    // int p;
    // cout <<"\nEnter value:"<<endl;
    // cin >> p;
    // pairs(p,a,b);

    // int k=2;
    // a.remove(k);

    // a.remove_duplicate();
    // a.swap_pair();

    a.print_list();
    node* newHead = a.zigZack(a.head);
    while(newHead)
      {
        cout <<newHead->data<<"->";
        newHead = newHead->next;
      }
    // a.even_or_odd();
    // *(a.head) = *(a.head->next);
    // a.print_list();

    // node* newHead = a.recursive_reverse(a.head);

    // while(newHead)
    //   {
    //     cout <<newHead->data<<"->";
    //     newHead=newHead->next;
    //   }
 return 0;
 }
