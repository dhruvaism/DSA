#include<iostream>
#include<math.h>
using namespace std;

#define n 3

bool inRow(int a[n][n],int r){
   for(int i=0;i<n;i++){
       if(a[r][i]==1){
           return true;
       }
   }
   return false;
}

bool inCol(int a[n][n],int c){
   for(int i=0;i<n;i++){
       if(a[i][c]==1){
           return true;
       }
   }
   return false;
}
bool inCross(int a[n][n],int r,int c){
   
   int rr = r;
   int cc = c;
   while(cc<n-1 && rr<n-1){
       if(a[++rr][++cc]==1)
        return true;
   }
   rr = r;
   cc = c;
   while(cc>0 && rr<n-1){
       if(a[++rr][--cc]==1)
        return true;
   }
   rr = r;
   cc = c;
   while(cc>0 && rr>0){
       if(a[--rr][--cc]==1)
        return true;
   }
    rr = r;
   cc = c;
   while(cc<n-1 && rr>0){
       if(a[--rr][++cc]==1)
        return true;
   }
   return false;
}

bool canPlace(int a[n][n],int r,int c){
    if(inRow(a,r) || inCol(a,c) || inCross(a,r,c))
       return false;
    return true;   
}

bool solve_nQueen(int a[n][n],int r){
    if(r==n){
        return true;
    }
    for(int c=0;c<n;c++){
        if(canPlace(a,r,c)){
            a[r][c]=1;
            if(solve_nQueen(a,r+1))
              return true;
            a[r][c]=0;  
        }
    }
    return false;

}


int main(){       

    int arr[n][n]={0};
    if(solve_nQueen(arr,0)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }else{
        cout<<"can't be solved"<<endl;
    }

    return 0;
}