
#include<iostream>

using namespace std;


struct node{
    int data;
    node* next;
    int extra;
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

    void segragate() {
       node *p1,*p2;
       p1 = head;
       node *new_tail;
       new_tail = tail;

       while((p1->data % 2) != 0 && p1!=tail)
           {
             head = p1->next;
             p1->next = NULL;
             new_tail->next = p1;
             new_tail = new_tail->next;
             p1 = head;
           }

        if((p1->data % 2)==0)
            {

                   while(p1!=tail)
                        {
                          if((p1->data % 2)==0)
                              {
                                p2 = p1;
                                p1=p1->next;


                              }
                            else
                               {

                                 p2->next = p1->next;
                                 new_tail->next = p1;
                                 new_tail=new_tail->next;
                                 new_tail->next = NULL;
                                 p1=p2->next;

                               }
                        }


            }

          if((p1->data % 2)!=0)
             {
               p2->next = p1->next;
               new_tail->next = p1;
               p1->next = NULL;
             }


    }


    node* segragateRecursive(node *h)
       {
         if(h->next==NULL)
            {
              if(h->data%2==0) 
                 return h;
              else
              {
                node *ptr = new node;
                ptr->data = 4;
                ptr->extra = 4;
                ptr->next = h;
                return ptr;
              }
                 
            }

           node* newHead = segragateRecursive(h->next);
          
              if(h->data % 2 == 0)
                {
                  node* temp = newHead->next;
                  newHead->next = h;
                  h->next = temp;
                }
               else
               {
                 node* ptr = newHead;
                 while(ptr->next!=NULL)
                   {
                     ptr=ptr->next;
                   }
                  ptr->next = h;
                  h->next = NULL;
               }
                

            
            return newHead;
              
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


int main(){

  //creating Object of Node class
    Node a;

  //taking input of data and Calling Add_node() function
    int n,m;
    for(int i=0;i<5;i++)
      {
        cin >>n;
        a.addNode(n);
      }
    a.print_list();
    // a.reverse();
    // a.print_list();
    node* node = a.segragateRecursive(a.head);

    if(node->extra == 4)
      {
        node=node->next;
      }
     while(node)
       {
         cout <<node->data<<"->";
         node=node->next;
       }

return 0;
}
