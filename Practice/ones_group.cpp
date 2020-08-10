#include<iostream>
#include<algorithm>
using namespace std;

#define n 6
int a[n][n];
int temp[n][n];

int getGroupSize(int t[n][n],int row,int col){
    if(row<0 || col<0 || row>=n || col>=n)
     return 0;


    if(t[row][col]==0)
     return 0;
    
    t[row][col]=0;
    return 1+getGroupSize(t,row,col-1)+getGroupSize(t,row-1,col)+getGroupSize(t,row,col+1)+getGroupSize(t,row+1,col);
   

    
}

int Search(int s,int e,int *queries,int toFind){
    if(s>e)
     return -1;
    for(int i=s;i<=e;i++){
        if(queries[i]==toFind)
         return i;
    } 
    return -1;
}

void getOnesGroup(int q,int *queries,int *ans){

       for(int j=0;j<n;j++){
           for(int k=0;k<n;k++){
               if(a[j][k]==1){
                   int size = getGroupSize(a,j,k); //find maximum group starting from next 1
                   int index = Search(0,q-1,queries,size); //search whether group size is existing in queries or not
                   if(index!=-1 && index<q){
                       ans[index]++;
                   }
                   cout<<endl;
            }

        }
}

   for(int i=0;i<q;i++){
       cout<<ans[i]<<" ";
   }
   cout<<endl;

}

int main(){

    
    for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
      cin>>a[i][j];

    int q;
    cin>>q;
    int queries[q];
    for(int i=0;i<q;i++)
     cin>>queries[i];
    

    int ans[q]={0};

    getOnesGroup(q,queries,ans);   

    return 0;
}