#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& parent,int currNode){
    visited[currNode] = true;

    for(int neightbour:adj[currNode]){
        if(!visited[neightbour]){
            parent[neightbour] = currNode;
            if(dfs(adj, visited, parent, neightbour)){
                return true;
            }
        }else if(parent[currNode] != neightbour){
            return true;
        }
    }
}

bool isCyclicDFS(vector<vector<int>>& edges,int numberNodes,int numberEdges){
    vector<vector<int>> adj(numberNodes+1);

    
    for(int i=0;i<numberEdges;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    vector<int> parent(numberNodes+1, -1);
    vector<bool> visited(numberNodes+1, false);

    for(int i = 1;i < numberNodes + 1;i += 1){
        if(visited[i]) continue;

        if(dfs(adj,visited,parent,i)){
            return true;
        }
    }
    return false;
}