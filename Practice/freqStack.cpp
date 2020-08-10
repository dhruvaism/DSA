#include<bits/stdc++.h>

using namespace std;

vector<stack<int>> vs;
unordered_map<int,int> counts;

void push(int x){
    int currCount =  counts[x];
    cout<<currCount<<endl;


}

int pop(){
  return 0;
}

int main(){

    push(1);
    push(1);
    push(2);
    push(3);
    //cout<<pop()<<endl;
    


    return 0;
}