#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int inFixEvaluation(string exp,int length)
  {
      stack<char> operat;
      stack<int> operand;
      for(int i=0;i<length;i++)
         {
          if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
             {
                 operat.push(exp[i]);
             }
           else if(exp[i]=='(')  
             {

             } 
           else if(exp[i]==')')
             {
                      int n1 = operand.top();
                 operand.pop();
                 int n2 = operand.top();
                 operand.pop();
                 char ch = operat.top();
                 operat.pop();
                 int n;
                 if(ch=='+')
                   {
                      n = n2 + n1;
                   }
                 else if(ch=='-')
                   {
                      n = n2 - n1;
                   } 
                 else if(ch=='*')
                   {
                      n = n1 * n2;
                   } 
                 else if(ch=='/')
                   {
                      n = n2 / n1;
                   } 
                  operand.push(n);                    
             }
             else
             {
                 operand.push(exp[i]-'0');
                 
             }
                

                
           
                
         }

        while(!operat.empty())
          {

                 int n1 = operand.top();
                 operand.pop();
                 int n2 = operand.top();
                 operand.pop();
                 char ch = operat.top();
                 operat.pop();
                 int n;
                 if(ch=='+')
                   {
                      n = n2 + n1;
                   }
                 else if(ch=='-')
                   {
                      n = n2 - n1;
                   } 
                 else if(ch=='*')
                   {
                      n = n2 * n1;
                   } 
                 else if(ch=='/')
                   {
                      n = n2 / n1;
                   } 
                  operand.push(n);                     

          }

         return operand.top();
  }

int main()
  {
      string exp;
      getline(cin,exp);
      int length = exp.size();
      
      cout <<"Evaluated Value: ";
      cout <<inFixEvaluation(exp,length)<<endl;
   

      return 0;
  }