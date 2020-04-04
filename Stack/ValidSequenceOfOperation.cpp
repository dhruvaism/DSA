#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isValidSequence(int push[],int pop[])
 {
      int j = 0; 
      
    // an empty stack 
    stack <int> st; 
    for(int i = 0; i < 5; i++){ 
        
        st.push(push[i]); 
        cout <<"push("<<st.top()<<")  ";

        // check if appended value is next to be popped out 
        while (!st.empty() && j < 5 && st.top() == pop[j]){ 
            cout <<"pop("<<st.top()<<")  ";
            st.pop(); 
            j++; 
        } 
    } 
      
    return j == 5; 
 }

int main()
 {
     int push[5];
     int pop[5];
     for(int i=0;i<5;i++)
       cin >>push[i];
     for(int i=0;i<5;i++)
       cin >>pop[i];

     if(isValidSequence(push,pop))
        {
            cout <<endl;
            cout <<"True"<<endl;
        }
       else
       {
           cout <<endl;
           cout <<"False"<<endl;
       }
        

 
     return 0;
 }