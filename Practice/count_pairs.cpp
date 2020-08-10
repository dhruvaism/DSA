#include<bits/stdc++.h>

using namespace std;

bool search(int no,int s,int e,int *arr){
    
    if(s>e)
     return false;

    int mid = (s+e)/2;
    if(arr[mid]==no)
     return true;
    else if(arr[mid]>no)
     return search(no,s,mid-1,arr);
    else
     return search(no,mid+1,e,arr);

    return false;    
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
     cin>>arr[i];
    int k;
    cin>>k;
    
    sort(arr,arr+n);
    
    unordered_map<int,bool> isDone;
    for(int i=0;i<n;i++){
        isDone[arr[i]]=false;
    }
    int i=0;
    int count=0;
    while(i<n-1){

        if(!isDone[arr[i]]){
            if(search(arr[i]+k,i+1,n-1,arr)){
               cout<<"("<<arr[i]<<","<<arr[i]+k<<"), ";
            }
        }
        isDone[arr[i]]=true;    
        i++;
    }
    cout<<endl;


    return 0;
}