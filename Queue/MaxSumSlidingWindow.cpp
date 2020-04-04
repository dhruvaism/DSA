#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void brutForceApproach(int arr[],int k,int n)
 {
     int b[n-k+1];
     int l=0;
     for(int i=0;i<=n-k;i++)
       {
           int max = arr[i];
           for(int j=0;j<k;j++)
             {
                 if(arr[i+j]>max)
                   max = arr[i+j];
             }
             b[l++]=max;
       }

       for(int i=0;i<l;i++)
         {
             cout <<b[i]<<" ";
         }
 }


int main()
 {
     int n=8;
     int arr[n];
     for(int i=0;i<8;i++)
       cin >>arr[i];
     int k;
     cout <<"window size: ";
     cin >>k;
     brutForceApproach(arr,k,n);  
 }