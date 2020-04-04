#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int popSmaller(stack<int> st, int arrvalue) 
  {
      int count=0;
      if(st.top()>arrvalue)
        {
             return 0;
        }
       int data = st.top();
       st.pop(); 
       count = 1+popSmaller(st,arrvalue);
       st.push(data);

       return count;

  }

 void spanUsingStack(int arr[],int span[])
   {

        stack<int> st;
        st.push(arr[0]);
        span[0]=1;
        for(int i=1;i<5;i++)
       {

            int c=popSmaller(st,arr[i]);
           
            st.push(arr[i]);
            span[i]= c+1;
       }
   } 

  void spanUsingArray(int arr[],int span[])
    {
        for(int i=0;i<5;i++)
          {
              int j=1;
              while(i>=j && arr[i]>=arr[i-j])
                {
                    j++;
                }

              span[i]=j;
          }
    } 


int main()
 {
     int arr[5];
     int span[5];

     for(int i=0;i<5;i++)
       cin>>arr[i];

     //Stack
     //spanUsingStack(arr,span);
      
     //Array
      spanUsingArray(arr,span); 

    for(int i=0;i<5;i++)
      {
          cout <<arr[i]<<"-->"<<span[i]<<endl;
      }


 }   