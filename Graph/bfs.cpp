#include<iostream>
#include<map>
#include<queue>
#include<list>

using namespace std;
class Graph{

    map<int,list<int>> l;
public:
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(int src){
        map<int,int> visited;
        queue<int> q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout<<node<<" ";
            for(int nbr:l[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
    }

    void printAdjList(){
        for(auto p:l){
            int v = p.first;
            list<int> nbrs = p.second;
            cout<<v<<" => ";
            for(int nbr:nbrs){
                cout<<nbr<<", ";
            }
            cout<<endl;
        }
    }
};


int main(){

    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.printAdjList();
    g.bfs(0);

    return 0;
}