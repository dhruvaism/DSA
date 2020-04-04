#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Stack
{
    queue<int> q1;  //PUshing
    queue<int> q2;  //Poping
};

Stack Push(int data,Stack st)
 {
    st.q1.push(data);
    return st;
 }

Stack Pop(Stack st)
 {
    while(!st.q1.empty())
      {
          int d = st.q1.front();
          st.q1.pop();
          if(!st.q1.empty())
             st.q2.push(d);
              
      }    
     while (!st.q2.empty())
     {
         st.q1.push(st.q2.front());
         st.q2.pop();
     }
     return st;
       
 }

void display(queue<int> q1,queue<int> q2)
 {
     while (!q1.empty())
     {
        cout<<q1.front()<<" ";
        q2.push(q1.front());
        q1.pop();
     }
     while (!q2.empty())
     {
         q1.push(q2.front());
         q2.pop();
     }
     
     
 }

int main()
 {
     int n,m;
     Stack st;
      while(1)
        {
            cin>>m;
            switch (m)
            {
            case 1: cout <<"Enter data: ";
                    cin>>n;
                    st=Push(n,st);
                
                break;
            case 2: st=Pop(st);
                break;
            case 3: display(st.q1,st.q2);
                break;        
            
            default:
                break;
            }
        }

 }