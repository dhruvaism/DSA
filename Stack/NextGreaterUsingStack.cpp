#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main()
 {
     int arr[10];
     int nextG[10];
     stack<int> st;
     int k=0;
     st.push(arr[0]);

     for(int i=0;i<10;i++)
       cin>>arr[i];
                
            

     for(int i=0;i<10;i++)
       {
           
           
           while(!st.empty() && st.top()<arr[i])
               {
                       cout <<st.top()<<" --> "<<arr[i]<<endl;
                       st.pop();
                       
               }

             st.push(arr[i]);    
                
            
             
       }
       while(!st.empty())
         {
              cout <<st.top()<<" --> "<<"No"<<endl;
              st.pop();
         }

     return 0;
 }