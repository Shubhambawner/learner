// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering.
// used in JOB scheduling: to do a job only if some other jobs are done, i.e. downloading/compiling  node_modules...

// indegree of vertex: no of dependancies it has, or no of adjescent nodes that are pointing to it
// indegree represents no. of nodes to be visited b4 visiting this vertex, or say no of dependencies of this module( if vertex is a module )
/*
find all with indegree 0, push in que
for each bottom vertex of que, untill it becoms empty.
    for each of its dependencies/adj vertces,
        reduce indegree by 1, and if that becoms 0 push them to que

if its asyclic grah, all the vertices will get indegree 0 at some or the other time

*/
#include <bits/stdc++.h>
using namespace std;

//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    vector<int> ans;
    int inDegree[V]={0};

    for(int i=0;i<V;i++){
        for(auto j:adj[i]){
            inDegree[j]++;
        }
    }
    bool visited[V]={0};
    list<int>que;
    
    for(int i=0;i<V;i++){
        if(inDegree[i]==0){
            que.push_back(i);
            visited[i]=1;
        }
    }
    while(que.size()!=0){
        int now = *que.begin();
        que.pop_front();
        ans.push_back(now);
        for(auto j:adj[now]){
            if(!visited[j]){
                inDegree[j]--;
                if(inDegree[j]==0){
                    visited[j]=1;
                    que.push_back(j);
                }
            }
        }
    }// 0 3
    return ans;
}