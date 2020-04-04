#include<bits/stdc++.h>
using namespace std;

#define n 4

bool findUnassignedPosition(int grid[n][n],int &r,int &c){
    for(r=0;r<n;r++)
     {
         for(c=0;c<n;c++)
          {
              if(grid[r][c]==0)
               return true;
          }
     }

     return false;
}

bool usedInCol(int grid[][n],int r,int c,int num){
    for(int i=0;i<n;i++)
     {
         if(grid[r][i]==num)
          return true;
     }
     return false;

}
bool usedInRow(int grid[][n],int r,int c,int num){
    for(int i=0;i<n;i++)
     {
         if(grid[i][c]==num)
          return true;
     }
     return false;

}

bool usedInBlock(int grid[][n],int r,int c,int num)
{
    int new_n = sqrt(n);
    int start_r = r - r%new_n;
    int start_c = c - c%new_n;
    for(int i=0;i<new_n;i++)
     {
         for(int j=0;j<new_n;j++)
         {
           if(grid[i+start_r][j+start_c]==num)
            return true;
         }
           
     }
     return false;
}

bool isSafe(int grid[][n],int r,int c,int num)
 {
      if(usedInCol(grid,r,c,num) || usedInRow(grid,r,c,num) || usedInBlock(grid,r,c,num))
       return false;
      return true; 
 }
bool solveSudoku(int grid[n][n]){
     int r,c;
     if(!findUnassignedPosition(grid,r,c))
      return true; 

     for(int i=1;i<=n;i++)
      {
          if(isSafe(grid,r,c,i))
          {
               grid[r][c] = i;
               if(solveSudoku(grid))
                return true;
               grid[r][c]=0; 
          }
      }  

      return false;
}

int main()
{
  
//    int grid[][n]={{8,9,2,0,0,5,0,0,3},
//                   {0,0,5,1,3,0,0,4,0},
//                   {0,4,0,7,0,5,5,0,0},
//                   {0,6,0,0,0,0,4,0,5},
//                   {0,1,0,0,0,0,0,3,0},
//                   {7,0,9,0,0,0,0,8,0},
//                   {0,0,6,8,0,1,0,9,0},
//                   {0,3,0,0,6,4,7,0,0},
//                   {4,0,0,3,0,0,2,6,1}};
int grid[][n]={{0,0,3,0},{0,4,0,0},{3,0,0,0},{0,0,4,0}};

    if(solveSudoku(grid)){
        for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++)
              cout<<grid[i][j]<<" ";
             cout<<endl; 
         }
    }else{
        cout<<"Not possible"<<endl;
    }              

}