#include<bits/stdc++.h>
using namespace std;

bool detectCycle(vector<vector<int>>& edges, int numberNodes, int numberEdges) {
    vector<vector<int>> adj(numberNodes);
    vector<int> indegree(numberNodes, 0);

    for(int i = 0;i < numberEdges;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for(int i = 0;i < numberNodes;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> res;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        res.push_back(node);

        for(int neighbour:adj[node]){
            indegree[neighbour] -= 1;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    if(res.size() != numberNodes) {
        return true;
    }

    return false;
}
