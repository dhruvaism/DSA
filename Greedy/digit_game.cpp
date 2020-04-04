/**
Arnab is playing a game. He is given a number N
 in string format and now he is asked to remove M
 digits from the number as a part of the game. Now Arnab wants to return with the maximum value of N
 possible. Print the maximum value of N
**/

#include<bits/stdc++.h>
using namespace std;



void buildLowestNumberRec(string str, int n, string &res) 
{ 
    // If there are 0 characters to remove from str, 
    // append everything to result 
    if (n == 0) 
    { 
        res.append(str); 
        return; 
    } 
  
    int len = str.length(); 
  
    // If there are more characters to remove than string 
    // length, then append nothing to result 
    if (len <= n) 
        return; 
  
    // Find the smallest character among first (n+1) characters 
    // of str. 
    int minIndex = 0; 
    for (int i = 1; i<=n ; i++) 
        if (str[i] > str[minIndex]) 
            minIndex = i; 
  
    // Append the smallest character to result 
    res.push_back(str[minIndex]); 
  
    // substring starting from minIndex+1 to str.length() - 1. 
    string new_str = str.substr(minIndex+1, len-minIndex); 
  
    // Recur for the above substring and n equals to n-minIndex 
    buildLowestNumberRec(new_str, n-minIndex, res); 
} 
  
// A wrapper over buildLowestNumberRec() 
string buildLowestNumber(string str, int n) 
{ 
    string res = ""; 
  
    // Note that result is passed by reference 
    buildLowestNumberRec(str, n, res); 
  
    return res; 
}

int main()
{
    int t;
    cin>>t;
    while(t--){

       string n;
       int m;
       cin>>n>>m;
      
       cout<<buildLowestNumber(n,m)<<endl;   

    }


   return 0;
}