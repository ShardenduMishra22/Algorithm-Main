#include <bits/stdc++.h>
using namespace std;

bool isCyclicBFS(vector<vector<int>>& edges,int numberNodes,int numberEdges){
    vector<vector<int>> adj(numberNodes+1);

    
    for(int i=0;i<numberEdges;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    queue<int> q;
    vector<int> parent(numberNodes+1, -1);
    vector<bool> visited(numberNodes+1, false);

    for(int i = 1;i < numberNodes + 1;i += 1){
        if(visited[i]){
            continue;
        }
        
        q.push(i);
        parent[i] = -1;
        visited[i] = true;

        while(!q.empty()){
            int currNode = q.front();
            q.pop();

            for(int neighbour:adj[currNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = currNode;
                }else if(parent[currNode] != neighbour){
                    return true;
                }
            }
        }
    }
}