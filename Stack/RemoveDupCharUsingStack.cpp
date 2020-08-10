#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void removeDup(string s)
  {
      unordered_map<char,int> map;
      int n = s.length();
      for(int i=0;i<n;i++){
        map[s[i]]++;
      }
      for(int i=0;i<n;i++){
        if(map[s[i]]==1){
          cout<<s[i];
        }
      }
      cout<<endl;
  }

int main()
  {
      string s;

      getline(cin,s);
      
      removeDup(s);
  }