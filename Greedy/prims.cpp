#include <bits/stdc++.h> 
using namespace std; 
  
// Number of vertices in the graph    
  
// A utility function to find the vertex with  
// minimum key value, from the set of vertices  
// not yet included in MST  
int minKey(int n,int key[], bool mstSet[])  
{  
    // Initialize min value  
    int min = INT_MAX, min_index;  
  
    for (int v = 0; v < n; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  
   
  

// Driver code 
int main()  
{  
   
   int n,m;
   cin>>n>>m;
   int graph[n][n];
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
     graph[i][j]=0;   
   }

  for(int i=0;i<m;i++)
   {
       int a,b,w;
       cin>>a>>b>>w;
       graph[a-1][b-1]=w;
       graph[b-1][a-1]=w;
   }

  // Array to store constructed MST  
    int parent[n];  
      
    // Key values used to pick minimum weight edge in cut  
    int key[n];  
      
    // To represent set of vertices not yet included in MST  
    bool mstSet[n];  
  
    // Initialize all keys as INFINITE  
    for (int i = 0; i < n; i++)  
        key[i] = INT_MAX, mstSet[i] = false;  
  
    // Always include first 1st vertex in MST.  
    // Make key 0 so that this vertex is picked as first vertex.  gf
    key[0] = 0;  
    parent[0] = -1; // First node is always root of MST  
  
    // The MST will have V vertices  
    for (int count = 0; count < n - 1; count++) 
    {  
        // Pick the minimum key vertex from the  
        // set of vertices not yet included in MST  
        int u = minKey(n,key, mstSet);  
  
        // Add the picked vertex to the MST Set  
        mstSet[u] = true;  
  
        for (int v = 0; v < n; v++)  
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])  
                parent[v] = u, key[v] = graph[u][v];  
    }  
  
   

    int ans=0;
    for (int i = 1; i < n; i++)  
      ans+=graph[i][parent[i]];
    
    cout<<ans<<endl;
  
   
  
    return 0;  
}