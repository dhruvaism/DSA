#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> st,int data)
  {
      if(st.empty())
        {
            st.push(data);
            return;
        }

       int d = st.top();
       st.pop();
       insertAtBottom(st,data);
       st.push(data); 
  }

void reverse(stack<int> st)
   {
       if(st.empty())
          return;
        int data = st.top();
        st.pop();
        reverse(st);  
        insertAtBottom(st,data);
   }

int main()
  {
      srand(time(0));
      stack<int> st;
      int k;
      for(int i=0;i<5;i++)
       {
            cin>>k;
            st.push(k);
            

       }
 cout <<"Reverse: "<<endl;

       reverse(st);

       while(!st.empty())
         {
             cout <<st.top()<<endl;
             st.pop();
         }

  }