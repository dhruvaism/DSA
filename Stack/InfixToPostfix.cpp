#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int precValue(char c)
   {
       if(c=='+' || c=='-')
          return 1;
       else if(c=='*' || c=='/')
          return 2;
       else
          return -1;       
   }

string postFix(string exp,int length)
  {

      stack <char> st;
      string result="";
      for(int i=0;i<length;i++)
        {
            if(exp[i] >= 'A' && exp[i] <= 'Z')
               {
                  
                   result.append(exp,i,1);
               }
             else if(exp[i] == '+'||exp[i] == '-'||exp[i] == '*' ||exp[i] =='/')
               {
                  
                  while(!st.empty() && precValue(st.top()) >= precValue(exp[i]))
                    {
                        result = result+st.top();
                        st.pop();
                    }
                  st.push(exp[i]);
               } 
              else if(exp[i]=='(')
                {
                    st.push(exp[i]);
                } 
               else  
               {
                   while(!st.empty() && st.top()!='(')
                      {
                          result = result+st.top();
                          st.pop();

                      }
                    st.pop();  
                   
               }
                
        }
        while(!st.empty())
           {
               result = result+st.top();
               st.pop();
           }

    return result;
  }   

  string preFix(string exp,int length)
    {


      stack <char> st;
      string result="";
      for(int i=0;i<length;i++)
        {
            if(exp[i] >= 'A' && exp[i] <= 'Z')
               {
                  
                   result.append(exp,i,1);

               }
             else if(exp[i] == '+'||exp[i] == '-'||exp[i] == '*' ||exp[i] =='/')
               {
                  
                  while(!st.empty() && precValue(st.top()) >= precValue(exp[i]))
                    {
                        string sss = "";
                        sss = sss+st.top();
                        sss = sss+result;
                        result = sss;
                        st.pop();
                    }
                  st.push(exp[i]);
               } 
              else if(exp[i]=='(')
                {
                    st.push(exp[i]);
                } 
               else  
               {
                   while(!st.empty() && st.top()!='(')
                      {
                          int l = result.size()-1;
                          int t=0;
                          string s1 = "";
                          string s2 = "";
                          while(t<l-1)
                            {
                                s1 = s1+result[t];
                                t++;
                            }
                          while(t<=l)
                           {
                               s2 = s2+result[t];
                               t++;
                           }  
                           s1=s1+st.top();
                           s1 = s1+s2;
                           result = s1;
                           


                          st.pop();

                      }
                    st.pop();  
                   
               }
                
        }
        while(!st.empty())
           {
              string ss = "";
              ss = ss+st.top();
              ss = ss+result;
              result = ss;
              st.pop();
           }

           return result;

  } 

      
    

int main()
  {
      string exp;
      getline(cin,exp);
      int length = exp.size();
      
      cout <<"POSTFIX: ";
      cout <<postFix(exp,length)<<endl;

      cout <<"PREFIX: ";
      cout <<preFix(exp,length)<<endl;


  }