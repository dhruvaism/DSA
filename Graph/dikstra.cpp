#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
   
      unordered_map<T,list<pair<T,int>>> l;
public:
   
 void addEdge(T x,T y,int wt){
       l[x].push_back(make_pair(y,wt));
       l[y].push_back(make_pair(x,wt));
       
   }

   void printAdjList(){
       for(auto p:l){
         string city = p.first;
         list<pair<string,int>> nbrs = p.second;
         cout<<city<<" => ";
         for(auto nbr:nbrs){
             string dest = nbr.first;
             int dist = nbr.second;
             cout<<dest<<" "<<dist<<", ";
         }
         cout<<endl;
       }
   }

   void dikstra(T src){
      
      unordered_map<T,int> dist;
      for(auto p:l){
          dist[p.first]=INT_MAX;
      }

      set<pair<int,T>> s;
      dist[src]=0;
      s.insert(make_pair(0,src));

      while(!s.empty()){

          auto p = *(s.begin());
          T node = p.second;
          int nodeDist = p.first;
          s.erase(s.begin());

          for(auto childPair:l[node]){

             if(nodeDist+childPair.second < dist[childPair.first]){

                 T childNode = childPair.first;
                 auto f = s.find(make_pair(dist[childNode],childNode));
                 if(f!=s.end()){
                     s.erase(f);

                 }
                 dist[childNode]=nodeDist+childPair.second;
                 s.insert(make_pair(nodeDist+childPair.second,childNode));
             }

          }


      }

      for(auto p:dist){
          cout<<"distance of "<<p.first<<" from "<<src<<" = "<<p.second<<endl;
      }



   }

};


int main(){

    Graph<string> g;
    g.addEdge("A","B",20);
    g.addEdge("A","C",10);

    g.printAdjList();
    g.dikstra("A");

    return 0;
}