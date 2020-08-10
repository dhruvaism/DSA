
//Spoj SUBSUMS
#include<iostream>
#include<math.h>
#include<vector>
#include<set>
using namespace std;


bool bSearch(int *a,int s,int e,int k){

    int mid = (s+e)/2;
    if(a[mid]==k)
     return true;
    if(s==e)
     return false; 
    else if(k<a[mid])
     return bSearch(a,s,mid,k);
    else 
     return bSearch(a,mid+1,e,k);
    
    return false;   

}

void findSubSums(int *a,int s,int e,vector<int> &v){
   int n = e-s+1;
   for(int i=0;i<1<<n;i++){
       int subsum=0;
       int no = i;
       int j=s;
       while(no>0){
          if(no&1!=0){
              subsum+=a[j];
          }
          j++;
          no = no>>1;
       }
       v.push_back(subsum);
       subsum = 0;
       j=0;
   }
}

int main(){       
    
    int n,a,b; //a & b are the range of sub sum
    cin>>n;
    cin>>a>>b;
    int arr[n];
    for(int i=0;i<n;i++)
     cin>>arr[i];
    vector<int> v1,v2;
    int mid = n/2;
    findSubSums(arr,0,mid,v1);
    findSubSums(arr,mid+1,n-1,v2);
    int count = 0;
    for(auto v:v1){
        for(auto vv:v2){
        if(v+vv >=a && v+vv <=b)
         count++;
    }
    }
    
    cout<<count<<endl;
     
  

    return 0;
}