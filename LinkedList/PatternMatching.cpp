#include<iostream>
using namespace std;

#define d 256

//NAIVE ALGORTHM
void naive(string Text,string Pat,int n,int m)
{
    int i,j;
    for(i=0;i<=n-m;i++)
      {
          for(j=0;j<m;j++)
            {
                if(Text[i+j]!=Pat[j])
                   break;
            }

          if(j==m)
            {
                cout <<"Pattern found at index: "<<i<<" " ;
            }  
      }

}

//OPTIMIZED NAIVE ALOGORITHM
void optimizedNaive(string Text,string Pat,int n,int m)
{
    int i=0,j;
    while(i<=n-m)
      {
          for(j=0;j<m;j++)
            {
                if(Text[i+j]!=Pat[j])
                   break;
                
            }
          if(j==m)
            {
                cout <<"Pattern found at index: "<<i<<" " ;
                i=i+j;
            }  
          else if(j==0)
            {
                i++;
            }  
          else
          {
              i=i+j;
          }
            
      }
}

//RABIN KARP ALGORITHM
void rabinKarp(string Text,string Pat,int n,int m)
{
    int i,j;
    int p=0,t=0,h=1;

    for(i=0;i<m-1;i++)
      {
          h=h*d;
      }
    for(i=0;i<m;i++)
      {
          p = p*d + Pat[i];
          t = t*d + Text[i];
      }  

    for(i=0;i<=n-m;i++)
      {
          if(t==p)
            {
                for(j=0;j<m;j++)
                  {
                      if(Text[i+j]!=Pat[j])
                         break;
                      
                  }
                if(j==m)
                  {
                     cout <<"Pattern found at index: "<<i<<" " ;
                
                  }    


            }

          if(i<n-m)
            {
               t = d*(t - Text[i]*h) + Text[i+m];
            } 
      }  
}

int main()
{
    string Text,Pat;
    cout <<"Enter Text: "<<endl;
    getline(cin,Text);
    cout <<"Enter Pattern: "<<endl;
    getline(cin,Pat);

    int n,m;

    m = Pat.length();
    n = Text.length();

    cout << "Text length: "<<n<<"\tPattern length: "<<m<< endl;

    //naive(Text,Pat,n,m);

    //optimizedNaive(Text,Pat,n,m);

    rabinKarp(Text,Pat,n,m);

}
