#include<iostream>
using namespace std;

void printEgyptian(int n, int d) 
{ 
  if(n==0||d==0)
  {
    return;
  }
  if(d%n==0)
  {
    cout << d/n <<" ";
    return;
  }
  if(n%d==0)
  {
    cout << "1/"<< n/d<<" ";
  }
  if(n>d)
  {
    cout << "1/"<<n/d<<" ";
    printEgyptian(n%d,d);
    return;
  }
  int num=d/n + 1;
  cout << num <<" ";
  printEgyptian(n*num-d,num*d);
 } 




int main()
 {
     int t;
     cin>>t;
     while(t--)
      {
          int n,d;
          cin>>n>>d;
          printEgyptian(n,d);
      }


      return 0;
 }