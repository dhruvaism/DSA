#include<iostream>
using namespace std;


int findWinCount(string str,int k)
{
    int ans=0;

    int n = str.length();
    bool temp[n] = {false};

    for(int i=0;i<n;i++)
     {
      if(str[i]=='1')
      {
           bool isDone=false;
           int j=i-k;
           if(j<0)
            j=0;
           while(j<=i-1)
            {
              if(str[j]=='0' && !temp[j])
               {
                   temp[j] = true;
                   isDone = true;
                   ans++;
                   break;
               }
               j++;
            } 
            
       j=i+1;
       while(!isDone && j<n && j<=i+k)
        {
            if(str[j]=='0' && !temp[j])
             {
                 temp[j]=true;
                 ans++;
                 break;
             }
             j++;
        }
      }


     }
 
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {

        string str;
        int k;
        cin>>str>>k;

        cout<<findWinCount(str,k)<<endl;
    
    }
    




    return 0;
}