#include<iostream>
using namespace std;

void toi(int n,char src,char dest,char via){

    if(n==1){
        cout<<src<<" to "<<dest<<" via "<<via<<endl;
        return;
    }
    toi(n-1,src,via,dest);
    toi(1,src,dest,via);
    toi(n-1,via,dest,src);
   

}

int main(){
    int n;
    cin>>n;
    toi(n,'A','C','B'); //A to C via B
}