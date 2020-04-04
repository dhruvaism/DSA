#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Queue{

    stack<int> st1; //S1 FOR PUSHING 
    stack<int> st2; //S2 FOR POPING
};


Queue enQueue(int data, Queue que)
  {
          que.st1.push(data);
          return que;

  }

Queue deQueue(Queue que)
  {
      if(!que.st2.empty())
        {
            que.st2.pop();
        }
      else
      {
           while(!que.st1.empty())
             {
                 que.st2.push(que.st1.top());
                 que.st1.pop();
             }
             que.st2.pop();
      }
      return que;
        
  }  

void pirntST1(stack<int> st1)
  {
      if(st1.empty())
        return;
      int d = st1.top();
      st1.pop();
      pirntST1(st1);
      st1.push(d);
      cout<<d<<" ";  
  }  

void printST2(stack<int> st2)
  {
    if(st2.empty())
       return;
    int d = st2.top();
    cout<<d<<" ";
    st2.pop();
    printST2(st2);
    st2.push(d);

  }  

void display(stack<int> st1,stack<int> st2)
  {
     if(!st1.empty() && st2.empty())
       {
          pirntST1(st1);
       }
     else if(st1.empty() && !st2.empty())
       {
           printST2(st2);
       }  
      else if(!st1.empty() && !st2.empty())
      {
          printST2(st2);
          pirntST1(st1);
      }
     else
     {
         cout<<"ENQUE IS EMPTY"<<endl;
     }
      
       

  }  

int main()
 {
     int m,n;
     Queue que;
      while(1)
        {
            cin>>m;
            switch (m)
            {
            case 1: cout <<"Enter data: ";
                    cin>>n;
                    que=enQueue(n,que);
                
                break;
            case 2: que=deQueue(que);
                break;
            case 3: display(que.st1,que.st2);
                break;        
            
            default:
                break;
            }
        }
 }