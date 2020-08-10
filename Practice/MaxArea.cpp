#include<iostream>
#include<stack>

using namespace std;

void maxArea(int n,int *a){
    stack<int> st;
    int i=0;
    int max=0;
    while(i<n){
        if(st.empty()||(a[st.top()]<=a[i])){
            st.push(i++);
        }
        else{
            int top = st.top();
            st.pop();
            int count = a[top]*(st.empty()?i:(i-st.top()-1));
            if(count>max){
              max = count;
            }
        }
    }
    while(!st.empty()){
        int top = st.top();
        st.pop();
        int count = a[top]*(st.empty()?i:(i-st.top()-1));
            if(count>max){
              max = count;
            }
    } 
    cout<<"Max area: "<<max<<endl;
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    maxArea(n,arr);    


    return 0;
}