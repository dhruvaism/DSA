#include<bits/stdc++.h>
using namespace std;


int findShelter(int *pos_m,int *pos_s,int n)
{
    int ans=0;
    sort(pos_m,pos_m+n);
    sort(pos_s,pos_s+n);

    for(int i=0;i<n;i++)
    {
        int diff = abs(pos_m[i]-pos_s[i]);
        if(diff>ans)
         ans+=diff-ans;
    }

    return ans;

}

int main()
{
    int t;
    cin>>t;
    while(t--){

       int n;
       cin>>n;
       int pos_men[n],pos_shelter[n];
       for(int i=0;i<n;i++)
         cin>>pos_men[i];
       for(int i=0;i<n;i++)
        cin>>pos_shelter[i];

       cout<<findShelter(pos_men,pos_shelter,n)<<endl;   

    }


   return 0;
}