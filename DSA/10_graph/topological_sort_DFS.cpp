// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering.

// using DFS : an unvisited vertex will be pushed to stack only after all its adjesents/dependants have been pushed, so while popping, it will come before all of its dependants/adjescant vertices

// while popping we get the order of topo sort

/*
 in DFS: we read vertex, then read all its dependants, here we read dependants, then vertex, then reverse it, 
 for example graph :
1 -> 2 <- 3
	in dfs, order is: 1, 2, 3

	for topo, we will start at 1, 
	push 2, then push 1, stack: [2, 1
	then push 3 [2, 1, 3
	so, while popping we get order: 3, 1, 2
*/

#include <bits/stdc++.h>
using namespace std;

void dfsTopo(int start,  vector<int> adj[], bool visited[],vector<int> &ans){
	    visited[start]=1;
	    for(auto i:adj[start]){
	        if(!visited[i]){
	            dfsTopo(i,adj,visited,ans);
	        }
	    }
	    ans.push_back(start);
	}
	
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    
	    
	    bool visited[V]={0};
	    
	    for(int i=0;i<V;i++){
	        if(!visited[i])
	            dfsTopo(i,adj,visited,ans);
	    }
	    
	    reverse(ans.begin(),ans.end());
	    
	    return ans;
	}