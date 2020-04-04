#include<bits/stdc++.h>
using namespace std;

struct task{
    int id,dead,prof;
};

bool compareProf(struct task t1,struct task t2)
{
   return t1.prof>t2.prof?true:false;
}

int findProfit(int n,struct task t[])
{
    int profit=0;
    sort(t,t+n,compareProf);
    int l=INT_MIN;
    for(int i=0;i<n;i++)
     {
         if(l<t[i].dead)
          l = t[i].dead;
     }
    bool slot[l]={false};
    for(int i=0;i<n;i++)
     {
         int j=t[i].dead-1;
         while(j>=0 && slot[j])
          {
              j--;
          }
         if(j!=-1) 
          {
              slot[j]=true;
              profit+=t[i].prof;
          }
      
     } 

     return profit;
}

int main()
 {
     int n;
     cin>>n;
     struct task t[n];
     for(int i=0;i<n;i++)
      {
        cin>>t[i].id>>t[i].dead>>t[i].prof;
      }

     cout<<findProfit(n,t)<<endl; 




     return 0;
 }