#include<iostream>
using namespace std;

int main()
 {
     int t;
     cin>>t;
     while (t--)
     {
         int w,n,m;
         cin>>w>>n>>m;
         bool isChanged = false;
         int ww = w;
         if(n<m)
          {
              n = n+m-(m=n);
              isChanged = true;
          }

         int x=0,y=0;
         if(w%n == 0)
          {
              x = w/n, y = 0;
          }
         else
         {
              do{
                 w=w-n;
                 x++;
         }while (w>n && w%m!=0);
             
            if(w%m ==0)
             {
                 y = w/m;
             } 
            else
            {
                while (w>m)
                {
                    w=w-m;
                    y++;
                }
                if(ww%m == 0)
                 {
                     x = 0,y = ww/m;
                 }
                
            } 
         }
          
         

        if(isChanged)
         {
             cout<<y<<" "<<x<<endl;
         } 
        else
        {
             cout<<x<<" "<<y<<endl;
        }
         
          


     }
     


     return 0;
 }