#include<bits/stdc++.h>

using namespace std;

int main()

{

       unordered_map <string, int> umap;
       string str = "I am Nitian i am Nitian ";

       stringstream s(str);
       string word;
 
       s << str+" Sikkim";
       while (s >> word)
       {
           cout <<word<<endl;
           umap[word]++;
       }
       
          for(auto x:umap)
            {
                cout <<"("<<x.first<<","<<x.second<<")"<<endl;
            }


       return 0;

}