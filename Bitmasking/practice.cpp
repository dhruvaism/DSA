#include<iostream>
#include<cstring>
using namespace std;

int countSetBits(int n){
    int count=0;
    while(n>0){
        if(n&1!=0)
         count++;
       n = n>>1; 
    }

    return count; 
}

void subStrings(string str){

   int n = str.length();
   for(int i=0;i<1<<n;i++){
       string temp="";
       int no = i;
       int j=0;
       while(no>0){
          if(no&1!=0){
              temp+=str[j];
          }
          j++;
          no = no>>1;
       }
       cout<<temp<<endl;
       temp="";
       j=0;
   }

}

//finding 2 unique no
void finding_uniques(int *arr,int n){
    int result; //contains result of unique no
    for(int i=0;i<n;i++){
        result^=arr[i];
    }
    int p=0; //position of first set bit
    while(result&1!=0){
        result = result<<1;
        p++;
    }
    int a=0,b=0;
    for(int i=0;i<n;i++){
        int j=p;
        int no = arr[i];
        while(j>0){
            no = no>>1;
            j--;
        }
        if(no&1!=0){
          a^=arr[i];
        }else{
            b^=arr[i];
        }
    }

    cout<<"1st no = "<<a<<endl;
    cout<<"2nd no = "<<b<<endl;

}




int main(){

    int arr[]={1,2,2,1,5,10,3,3};
    finding_uniques(arr,8);

    return 0;
}