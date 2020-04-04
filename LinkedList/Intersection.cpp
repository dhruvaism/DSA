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

    //printing from reverse
    
    void print_list_rev(node *head)
       {
           if(head==NULL)
              {
                  return ;
              }
            
            print_list_rev(head->next);

            cout <<head->data<<endl;
            
              
       }  
   
 

};

void join(Node a, Node b){
    int data;
    srand(time(0));
    for(int i=0;i<5;i++)
      {
           data= rand()%20;
           node *temp = new node;
           temp->data=data;
           temp->next=NULL;
           a.tail->next=temp;
           b.tail->next=temp;
           a.tail=a.tail->next;
           b.tail=b.tail->next;

      }

}
//Runtime O(nm)
int intersect_point1(Node a, Node b){

   node *p1,*p2;
   p1=a.head;
   
   cout <<"Checking..."<<endl;
  
   while(p1!=NULL)
      {
          p2 = b.head;
           while (p2!=NULL)
           {
               if(p1 == p2)
                  {
                     
                      return p1->data;
                  }
                else
                {
                     
                    p2=p2->next;
                }
                  
           }
           p1=p1->next;
      }
      return 0;

}

//Runtime O(n)  if  n>m
void intersect_point2(Node a, Node b){
  
   unordered_map<node*, int> umap;
   node* p1, * p2;
   p1=a.head;
   p2=b.head;

   while(p1!=NULL)
      {
          umap[p1]++;
          p1=p1->next;
      }
   while (p2!=NULL)
      {
          if(umap.find(p2)!=umap.end())
           {
               cout <<p2->data<<"->";
           }
           p2=p2->next;
             
      }
  
      

}

int main(){

    Node a,b;
    int data;
    
    cout <<"Enter node data List1:"<<endl;
    for(int i=0;i<3;i++)
       {
           cin >>data;
           a.addNode(data);
       }
     cout <<"Enter node data List2:"<<endl;  
      for(int i=0;i<4;i++)
       {
           cin >>data;
           b.addNode(data);
       }  
      join(a,b);
      cout <<"LIST 1 and 2 are joined"<<endl;

      a.print_list();
      b.print_list();

     intersect_point2(a,b);
     // cout <<intersect_point2(a,b)<<endl;
    //a.print_list_rev(a.head);

}