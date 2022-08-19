#include "../util/recursion_utilities.cpp"

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
  bool cycDfs(int start, vector<int> adj[], vector<bool>& visited, vector<bool>& path){
    //   e(start,path,visited);
      bool cyc = false;
      path[start]=1;
      visited[start]=1;
      for(auto i:adj[start]){
          if(path[i])return true;
          if(!visited[i])
          cyc = cyc || cycDfs(i,adj,visited,path);
      }
      path[start]=0;
    //   b(cyc);
      return cyc;
  }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<bool> visited(v,0);
        vector<bool> path(v,0);

        bool cyc = false;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                cyc = cycDfs(i,adj,visited,path);
            }
        }
        
        return cyc;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends