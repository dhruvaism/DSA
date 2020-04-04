#include<iostream>
using namespace std;

bool place(int k,int i,int x[])
 {
    for(int j=0;j<k;j++)
     {
          if((x[j]==i) || (abs(k-j)==abs(i-x[j])))
           {
               return false;
           }
     }

     return true;
 }

 void print(int n,int x[])
  {
      for(int i=0;i<n;i++)
        cout<<x[i]<<" ";
      cout<<endl; 
  }

void nqueen(int k,int n,int x[])
 {
     for(int i=0;i<n;i++)
      {
          if(place(k,i,x))
           {
               x[k]=i;
               if(k==n-1)
                {
                    print(n,x);
                    return;
                }
               else
               {
                   nqueen(k+1,n,x);
               }
                
           }
      }
 }

int main()
 {

     int n;
     cin>>n;

     int x[n];
     nqueen(0,n,x);
     

     return 0;
 }