#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
  {
      int data;
      node * next;
      int cary;
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


        

        void reOrder()
          {
              node *middle,*end;
              end = head;
              middle = head;
              node *end1 = head;

              while(end1->next)
                {
                    end1=end1->next;
                }

              while(end->next!=end1 && end!=end1)
                {
                    end=end->next->next;
                    middle=middle->next;
                }

              node * temp = middle->next;
              stack<node *> st;
              while(temp)
                {
                    st.push(temp);
                    temp=temp->next;
                }  
                end = head;
                while(end!=middle->next)
                  {
                    if(st.empty())
                      {
                          break;
                      }
                     node *t = end->next;
                     end->next=st.top();
                     st.pop();
                     end->next->next=t;
                     end=t;
                     

                  }
                  end->next = NULL;


             
          }


};

void addDigitOfList(Node a, Node b)
   {
       node *node1, *node2;
       stack <node*> s1,s2;

       node1 = a.head;
       node2 = b.head;

       while(node1)
         {
            s1.push(node1);
            node1=node1->next;
            
         }
        while (node2)
        {
            s2.push(node2);
            node2=node2->next;
           
        }
         
         int result =0, d1 =0, d2 =0;
         node* nhead=NULL;
        while(!s1.empty() || !s2.empty())
            {

                
                if(s1.empty() && !s2.empty())
                  {
                      node2 = s2.top();
                      s2.pop();
                      result = node2->data;

                  }
                 else if(!s1.empty() && s2.empty())
                 {
                     node1 = s1.top();
                     s1.pop();
                     result = node1->data;
                    
                 }
                 else
                 {
                      node1 = s1.top();
                      node2 = s2.top();
                      s1.pop();
                      s2.pop();
                      result = node1->data + node2->data;
                 }
                 
                     

                if(result>=10)  // if result = 12
                  {
                      d1 = result/10; // d1 = 1
                      d2 = result%10;  //d2 = 2

                      node* temp1 = new node;
                      temp1->data=d1;
                      temp1->next=NULL;

                      node* temp2 = new node;
                      temp2->data=d2;
                      temp2->next = NULL;

                      if(nhead == NULL)
                        {
                            
                            temp1->next= temp2;
                            nhead  = temp1;
                        }
                        else
                        {
                            temp2->next=nhead;
                            temp1->next=temp2;
                            nhead = temp1;
                        }

                  }
                  else
                  {
                       node* temp1 = new node;
                      temp1->data=result;
                      temp1->next=NULL;

                      if(nhead == NULL)
                         {
                             nhead = temp1;
                         }
                        else
                        {
                            temp1->next = nhead;
                            nhead = temp1;
                        }
                         
                      
                  }
                  
                

            }

           while (nhead)
           {
               cout <<nhead->data<<"->";
               nhead=nhead->next;
           }
            

   }



//Recursive Addition
        int cary = -1;
        node * addDigit(node* a,node* b)
          {

                if(!a->next && !b->next)
                  {
                     int d = a->data + b->data;
                     int d1 = d/10;
                     int d2 = d%10;
                     cary = d1;
                     node* n = new node();
                     n->data = d2;
                     n->next = NULL;
                     n->cary = cary;
                     return n;
                       
                  }
                  node* newnode = addDigit(a->next,b->next);
                  int d = (a->data + b->data)+cary;
                  int d1 = d/10;
                  int d2 = d%10;
                  cary = d1;
                  node *temp = new node;
                  temp->data = d2;
                  temp->next = newnode;
                  newnode = temp;
                  newnode->cary = cary;

                  
                 return newnode;


          }

   int carry = -1;
   node* addRemainingDigit(node*a, node*p, node*f)
      {
        if(a->next==p)
           {
             node* temp = new node;
             int d = a->data+f->cary;
             int d1 = d/10;
             int d2 = d%10;
             carry = d1;
             temp->data = d2;
             temp->next = f;
             temp->cary = carry;
             return temp;
           }
           node* newNode = addRemainingDigit(a->next,p,f);
           int dd = a->data+carry;
           int dd1 = dd/10;
           int dd2 = dd%10;
           carry = dd1;
           node* newn = new node;
           newn->data = dd2;
           newn->next = newNode;
           newNode = newn;
           newNode->cary = carry;

           return newNode;
      }

int main(){
    Node a,b;
    int n;
    for(int i=0;i<10;i++)
         {
           scanf("%d",&n);
           a.add_node(n);
         }
    for(int i=0;i<10;i++)
         {
           scanf("%d",&n);
           b.add_node(n);
         }  

    a.print_list();
    b.print_list();
    // addDigitOfList(a,b);        
    // a.reOrder();
    // a.print_list();
    int l1=0,l2=0,c=0;
    node*p1 = a.head;
    node*p2 = b.head;
    while(p1)
      {
        l1++;
        p1=p1->next;
      }
     while(p2)
       {
         l2++;
         p2=p2->next;
       } 

     p1 = a.head;
     p2 = b.head;
     if(l1>l2)
       {
          int diff=l1-l2;
          while(diff--)
            {
               p1=p1->next;
            }
           
       }  

        if(l2>l1)
       {
          int dif=l2-l1;
          while(dif--)
            {
               p2=p2->next;
            }
           
       } 

    node* newHead = addDigit(p1,p2);


    if(l1>l2)
      {
        node* newHead1 = addRemainingDigit(a.head,p1,newHead);
        newHead = newHead1;
      }

    if(l1<l2)
      {
         node* newHead2 = addRemainingDigit(b.head,p2,newHead);
         newHead = newHead2;
      }  
   

    if(newHead->cary > 0)
      {
        node* t = new node;
        t->data = newHead->cary;
        t->next = newHead;
        newHead = t;

      }
    
   
    while(newHead)
      {
        cout <<newHead->data<<"->";
        newHead =newHead->next;
      }
    

    

    return 0;     

}
