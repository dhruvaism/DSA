
// minimum no od dice played to rich upto 36th position in ladder-snake board?


#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
 unordered_map<T,list<T>> g;
 public:
  void addEdge(T x,T y){
      g[x].push_back(y);
      g[y].push_back(x);
  }

  void printEdge(){
      for(auto n:g){
          cout<<n.first<<" => ";
          for(auto p:n.second){
              cout<<p<<",";
          }
          cout<<endl;
      }
  }

  void bfs(int src){
        map<int,int> visited;
        queue<int> q;
        map<T,int> dist;
        q.push(src);
        visited[src]=true;
        dist[src]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int nbr:g[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                    dist[nbr] = dist[node]+1;
                }
            }
        }

        cout<<"minimum dist: "<<dist[36]<<endl; 
    }


};  

int main(){

    int d[50]={0};
     d[2]=13;
     d[5]=2;
     d[17]=-13;
     d[18]=11;      //+ve for ladder
     d[20]=-14;     //-ve for snake
     d[24]=-8;
     d[25]=10;
     d[32]=-2;
     d[34]=-22;
    
    Graph<int> g;
    //to insert edge
    for(int u=0;u<36;u++){
       //dice
       for(int i=1;i<=6;i++) {
           if(u+i+d[u+i]<=36){
               int v = u+i+d[u+i];
               g.addEdge(u,v);
           }
       }
    }
    g.bfs(0);

    return 0;
}