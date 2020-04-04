#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void display(stack<char> st)
  {
      if(st.empty())
         return;
      char c = st.top();
      st.pop(); 
      display(st);  
      cout <<c;
      st.push(c);
      
  }

void removeDup(string s)
  {
      stack<char> st;
      for(int i=0;i<s.size();i++)
         {
             if(st.empty() || st.top()!=s[i])
                {
                    st.push(s[i]);
                }
              else
              {
                  st.pop();
              }
                
         }

         display(st);
  }

int main()
  {
      string s;

      getline(cin,s);
      removeDup(s);
  }