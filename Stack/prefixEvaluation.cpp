#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int preFixEvaluation(string exp,int length)
  {
       stack<int> st;
       int i=length-1;
       while(i>=0)
       {
       if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
             {

                 int n1 = st.top();
                 st.pop();
                 int n2 = st.top();
                 st.pop();
                 int n;
                 if(exp[i]=='+')
                  {
                     n=n1+n2;
                  }
                 else if(exp[i]=='-') 
                  {
                      n=n1-n2;
                  }
                 else if(exp[i]=='*')
                  {
                      n = n1*n2;
                  }
                 else
                 {
                     n = n1/n2;
                 }
                 st.push(n);
                   
             }
           else
           {
               int n = exp[i] - '0';
               st.push(n);
               
               
           }
           i--;
                
         }

         return st.top();
  }

int main()
  {
      string exp;
      getline(cin,exp);
      int length = exp.size();
      
      cout <<"Evaluated Value: ";
      cout <<preFixEvaluation(exp,length)<<endl;
   

      return 0;
  }