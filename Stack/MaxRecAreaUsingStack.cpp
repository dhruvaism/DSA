#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void nSquareApproach(int height[])
  {
      int max=-1;
      for(int i=0;i<1000000;i++)
        {
            
            int count=0;
            int j=i;
            while(height[i]<=height[j] && j<1000000)
              {
                  count++;
                  j++;
              }
              j=i-1;
            while(height[i]<=height[j] && j>-1)
              {
                  count++;
                  j--;
              }  
            count = count*height[i];
           
            if(count>max)
              {
                  max=count;
              }  
              
        }
      cout <<"\nMaximum Rectangular Area: "<<max<<endl;  
  }

  void nApproach(int height[])
    {
        stack<int> st;
        int max=-1;
        int i=0;
        while(i<1000000)
          {
             
            if(st.empty()||(height[st.top()]<=height[i]))
               {
                   st.push(i++);
               }   
             else
               {
                   int top = st.top();
                    st.pop();
                    int count = height[top]*(st.empty()? i: i-st.top()-1);
                    if(count>max)
                       max = count;
               }  



          }

         while(!st.empty())
            {
                int top = st.top();
                    st.pop();
                    int count = height[top]*(st.empty()? i: i-st.top()-1);
                    if(count>max)
                       max = count;
            } 


           cout <<"maximum rectangular area: "<<max<<endl; 
    }

int main()
  {
      srand(time(0));
      int n=1000000;
      int height[n];
      cout <<"Enter Heights:";
      for(int i=0;i<n;i++)
        {
            height[i] = 1+rand()%100000000;
        }
      nApproach(height);
      nSquareApproach(height);  
      
  }