#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj,vector<bool>& visited,vector<bool>& visitedDfs,int currNode){
    visited[currNode] = true;
    visitedDfs[currNode] = true;

    for(int neighbour:adj[currNode]){
        if(!visited[neighbour]){
            if(dfs(adj, visited, visitedDfs, neighbour)){
                return true;
            }
        }else if(visitedDfs[neighbour]){
            return true;
        }
    }

    visitedDfs[currNode] = false;
    return false;
}

bool isCyclicDFS(vector<vector<int>>& edges,int numberNodes,int numberEdges){
    vector<vector<int>> adj(numberNodes+1);

    for(int i=0;i<numberEdges;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(numberNodes+1,false);
    vector<bool> visitedDfs(numberNodes+1,false);

    for(int i = 1;i < numberNodes + 1;i += 1){
        if(visited[i]){
            continue;
        }

        if(dfs(adj, visitedDfs, visited, i)){
            return true;
        }
    }

    return false;
}