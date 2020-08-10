#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
 unordered_map<T,list<pair<T,int>>> g;
 public:
  void addEdge(T x,T y,int wt){
      g[x].push_back(make_pair(y,wt));
      g[y].push_back(make_pair(x,wt));
  }

  void printEdge(){
      for(auto n:g){
          cout<<n.first<<" => ";
          for(auto p:n.second){
              cout<<"("<<p.first<<","<<p.second<<"), ";
          }
          cout<<endl;
      }
  }

  void bfs(T src){
      queue<T> q;
      unordered_map<T,bool> visited;

      q.push(src);
      visited[src]=true;

      while(!q.empty()){
          T node = q.front();
          q.pop();
          cout<<node<<", ";
          for(auto p:g[node]){
             
             if(!visited[p.first]){
                  q.push(p.first);
                  visited[p.first]=true;
             }
              
          }
      }
      cout<<endl;

  }

  void dfs_helper(stack<T> &s, unordered_map<T,bool> &visited){

     if(s.empty())
      return;

     T node = s.top();
     cout<<node<<", ";
     for(auto p: g[node]){
         if(!visited[p.first]){
          s.push(p.first);
          visited[p.first]=true;
          dfs_helper(s,visited);
          s.pop();
         }
              
        }

  }

  void dfs(T src){
      stack<T> s;
      unordered_map<T,bool> visited;
      s.push(src);
      visited[src]=true;
      dfs_helper(s,visited);
      cout<<endl;
  }
 
  void dikstra(T src){
      unordered_map<T,int> dist;

      for(auto node:g){
          dist[node.first]=INT_MAX;
      }
      dist[src]=0;
      set<pair<int,T>> s;
      s.insert(make_pair(0,src));

      while(!s.empty()){
          auto p = *(s.begin());
          T node = p.second;
          int parent_dist = p.first;
          s.erase(p);
          for(auto pp:g[node]){
              T nbr = pp.first;
              int child_dist = pp.second;
              if(parent_dist+child_dist < dist[nbr]){
                 
                 auto f = s.find(make_pair(dist[nbr],nbr));
                 if(f!=s.end()){
                     s.erase(f);
                 }
                 dist[nbr] = parent_dist+child_dist;
                 s.insert(make_pair(dist[nbr],nbr));
              }

          }
      }

      for(auto d:dist){
          cout<<d.first<<" from "<<src<<" = "<<d.second<<endl;
      }

  } 



};

main(){

    Graph<string> g;
    g.addEdge("A","B",2);
    g.addEdge("B","C",5);
    g.addEdge("A","C",1);
    g.addEdge("A","E",4);
    g.addEdge("E","D",1);
    g.addEdge("D","B",3);
    g.addEdge("D","C",6);
    g.printEdge();
    g.dikstra("A");

}
