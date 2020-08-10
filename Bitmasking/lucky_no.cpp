#include<iostream>
using namespace std;

int findNoDigit(int n){
      int count=0;
      while(n>0){
          count++;
          n=n/10;
      }
      return count;
}

void findIndex(int n){
   int d = findNoDigit(n);
   int index=0;
   d=d-1; //for 1 less digits
   while(d>0){
       index+=1<<d;
       d--;
   }

   d = findNoDigit(n);
   int currentDigit  = -1;
   for(int i=0;i<1<<d;i++){
       int new_n = n;
       int new_i = i;
       while(new_n>0){
           currentDigit = new_n%10;
           int ith = new_i&1;
           if((ith==0 && currentDigit==7)||(ith==1 && currentDigit==4)){
               break;
           }
           new_i = new_i>>1;
           new_n = new_n/10;
       }

       index++;
       if(new_n==0){
           break;
       }
   }

   cout<<index<<endl;
  
}

int main(){

    int n;
    cin>>n;

    findIndex(n); //find index of lucky contains 4 or 7 or both


    return 0;
}