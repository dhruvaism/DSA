// Codechef TSHIRTS

#include<bits/stdc++.h>

using namespace std;

#define ll long long int

//for reverse mapping
vector<vector<int>> v;
int ALL_PERSON;
ll dp[1025][102]; //as per constraints

int stoi(string &s){
    stringstream ss (s);
    int x;
    ss>>x;
    return x;
}

int main(){

    v.reserve(110);
    int t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        int n;
        cin>>n;
        ALL_PERSON = (1<<n)-1;

        for(int i=0;i<=100;i++){
            v[i].clear();
        }
        cout<<n<<endl;
        for(int i=0;i<n;i++){
                    string s;
            getline(cin,s);
            stringstream ss (s);
            string temp;
            while(ss>>temp){
                v[stoi(temp)].push_back(i);
            }
        }

        for(int i=0;i<=100;i++){
            sort(v[i].begin(),v[i].end());
            if(v[i].size()>0){
                cout<<"T-Shir t"<<i<<" -> ";
                for(auto j:v[i]){
                    cout<<"P"<<j<<", ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}