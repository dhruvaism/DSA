#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int postFixEvaluation(string exp,int length)
  {
      stack<int> st;
      for(int i=0;i<length;i++)
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
                     n=n2+n1;
                  }
                 else if(exp[i]=='-') 
                  {
                      n=n2-n1;
                  }
                 else if(exp[i]=='*')
                  {
                      n = n2*n1;
                  }
                 else
                 {
                     n = n2/n1;
                 }
                 st.push(n);
                   
             }
           else
           {
               int n = exp[i] - '0';
               st.push(n);
               
               
           }
           
                
         }

         return st.top();
  }

int main()
  {
      string exp;
      getline(cin,exp);
      int length = exp.size();
      
      cout <<"Evaluated Value: ";
      cout <<postFixEvaluation(exp,length)<<endl;
   

      return 0;
  }