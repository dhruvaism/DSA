#include<iostream>
using namespace std;
int n;

bool isSafe(int x,int y,int **maze)
 {
     if(x>=0 && x<n && y>=0 && y<n && maze[x][y]==1)
      return true;
     return false; 
 }


bool isPossiblePath(int x,int y,int **maze)
{
       if(x==n-1 && y==n-1)
        return true;
       if(isSafe(x,y,maze))   //1 safe, 0 not safe 
        {
            if(isPossiblePath(x+1,y,maze))
             return true;
            if(isPossiblePath(x,y+1,maze))      //backtracking
             return true;

            return false;  
        }

        return false;


} 


int main()
 {
     
     cin>>n;
     int** maze = new int*[n];

     for(int i=0; i<n; i++)
     {
        maze[i] = new int[n];
     }

     for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
       cin>>maze[i][j];

     if(isPossiblePath(0,0,maze))
      cout<<"Yes"<<endl;
     else
      cout<<"No"<<endl;    


     return 0;
 }