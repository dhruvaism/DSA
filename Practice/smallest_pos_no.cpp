#include<iostream>
#include<cstdlib>

using namespace std;

int findSmallestPositive(int n,int *arr){

    int ans=0;
    for(int i=0;i<n;i++){
        if(arr[i]>=0 && arr[i]<n){
            int index = arr[i];
            swap(arr[i],arr[index]);
        }
    }

    for(int i=0;i<n;i++){
        if(arr[i]!=i && i!=0){
            return i;
        }
        // cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
     cin>>arr[i];

    cout<<findSmallestPositive(n,arr)<<endl; 


    return 0;
}