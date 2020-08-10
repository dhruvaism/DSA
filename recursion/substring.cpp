#include<iostream>

using namespace std;

void substrings(char *in,char* out, int i,int j){
    if(in[i]=='\0'){
       cout<<out<<endl;
       return;
    }

    out[j]=in[i];
    substrings(in,out,i+1,j+1);
    out[j]='\0';
    substrings(in,out,i+1,j);
}

int main(){

    char str[100],out[100];
    cin>>str;
    substrings(str,out,0,0);

    return 0;
}