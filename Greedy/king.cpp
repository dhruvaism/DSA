#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin >> arr[i];
    }
    sort(arr,arr+n);
    stack<int> st;
    for(int i=n-1;i>=0;i--)
    { 
      st.push(arr[i]);
    }
    int sum=0;
    for(int i=0;i<n-1;i++)
    {
      int n1=st.top();
      st.pop();
      int n2=st.top();
      st.pop();
      int num=n1+n2;
      sum+=num;
      int count=0;
      int temp[n];
      while(st.size()>0)
      {
        int upp=st.top();
        if(num<upp){
			break;
		}
        st.pop();
        temp[count++]=upp;
      }
      st.push(num);
      while(count>0)
      {
        st.push(temp[count-1]);
        count--;
      }
    }
    cout<< sum <<endl;
  }
  
  return 0;
}