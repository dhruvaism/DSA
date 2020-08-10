#include<iostream>
using namespace std;


int partition(int *a,int s,int e){

    int pivot = a[e];
    int j = s-1;
    int i=s;
    while(i<e){
        if(a[i]<=pivot){
            j++;
            swap(a[i],a[j]);
        }
        i++;
    }
    j++;
    swap(a[i],a[j]);
    return j;

}


void q_sort(int *a,int s,int e){
    if(s<=e){
        int index = partition(a,s,e);
        q_sort(a,s,index-1);
        q_sort(a,index+1,e);
    }
}

int nthFib(int n,int *a){
    if(n==0 || n==1){
        a[n]=n;
        return a[n];
    }
    if(a[n]!=0)
     return a[n];
    a[n]=nthFib(n-1,a)+nthFib(n-2,a);
    return a[n];
}

int main(){
    int n;
    cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    // q_sort(arr,0,n-1);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    int a[n+1]={0};
    cout<<nthFib(n,a)<<endl;
    return 0;
}