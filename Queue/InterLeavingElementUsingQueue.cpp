#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void display(queue<int> q)
 {
     stack<int> st;
     while (!q.empty())
     {
         cout <<q.front()<<" ";
         st.push(q.front());
         q.pop();
         
     } 

 }
queue<int> interLeave(queue<int> q) 
 {
     int halfsize = q.size()/2;
     stack<int> st;
     for(int i=0;i<halfsize;i++)
       {
         st.push(q.front());
         q.pop();
       }
      while(!st.empty())
        {
            q.push(st.top());
            st.pop();
        } 
       for(int i=0;i<halfsize;i++)
         {
             q.push(q.front());
             q.pop();
         } 
       
         for(int i=0;i<halfsize;i++)
         {
             st.push(q.front());
             q.pop();
         } 
        while(!st.empty())
         {
             q.push(st.top());
             st.pop();
             q.push(q.front());
             q.pop();
         }  
         return q;
        

 } 


 
int main()
  {
      srand(time(0));
      queue<int> q;
      int n=8;
      for(int i=0;i<n;i++)
        {
            q.push(1+rand()%20);
        }
      display(q);
      q=interLeave(q);
      cout <<endl;
      display(q);

  }