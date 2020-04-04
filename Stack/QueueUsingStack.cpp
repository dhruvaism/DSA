#include<iostream>
#include<bits/stdc++.h>
using namespace std;

stack<int> enqueue(stack<int> st,int data)
  {
      
      st.push(data);
      return st;
      

  }

stack<int> dequeue(stack<int> st)
   {
      
      int d = st.top();
      st.pop();
      if(st.empty())
        return st;

      st=dequeue(st);  
      st.push(d);

      return st;
   }
 void display(stack<int> st)
   {
       if(st.empty())
         return;
       cout <<st.top()<<" ";  
       int d = st.top();
       st.pop();
       display(st);  
       st.push(d);
       

   }  

int main()
  {
      srand(time(0));
      stack<int> st;
      int k;
      for(int i=0;i<3;i++)
       {
            cin>>k;
            st.push(k);
        
       }

      

       //ENQUEUE
       int n;
       cout <<"Data for Enqueue: ";
       cin >>n;
       st = enqueue(st,n);
       cout <<"Display: ";
       display(st);
       cout <<endl;

       //DEQUEUE
       st = dequeue(st);
       cout <<"Display: ";
       display(st);
       cout <<endl;

      
       

       
    

  }
