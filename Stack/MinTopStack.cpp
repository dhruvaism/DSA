#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
  {
      srand(time(0));
      stack<int> st;
      for(int i=0;i<5;i++)
        {
            if(st.empty())
               st.push(5+rand()%20);
            else
            {
                int n = 5+rand()%20;
                if(n<=st.top())
                  {
                     st.push(n);
                  }
                else
                {
                    int k = st.top();
                    st.pop();
                    st.push(n);
                    st.push(k);
                }
                  
            }
               
        }
       cout <<"Min Top: ";
       while(!st.empty())
         {
             cout <<st.top()<<endl;
             st.pop();
         } 

   return 0;
  }