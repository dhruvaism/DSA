#include<iostream>
#include<stack>

using namespace std;

int main()
{
    

    string input1;
    cout <<"String: "<<endl;
    getline(cin,input1);

    stack<char> st;
    int count=0;
    
    for(int i=0;i<input1.size();i++)
     {
           switch(input1[i])
             {
                case '(':st.push(input1[i]);
                         break;
                case '[':st.push(input1[i]);
                         break;
                case '{':st.push(input1[i]);
                         break;
                case ']':if(st.top()=='[' && !st.empty())
                            {
                                st.pop();
                                count++;
                            }
                            break;
                case '}':if(st.top()=='{' && !st.empty())
                            {
                                st.pop();
                                count++;
                            }
                            break;
                case ')':if(st.top()=='(' && !st.empty())
                            {
                                st.pop();
                                count++;
                            }
                            break;                        

             }

     }

   

   cout<<count<<endl;
      
}
