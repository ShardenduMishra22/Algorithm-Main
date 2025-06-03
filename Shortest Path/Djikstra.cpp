#include<bits/stdc++.h>
using namespace std;

using P = pair<int, int>; // Pair of (node, weight)

vector<int> shortestPath(vector< vector<int> > &edge, int edges, int nodes, int src){
    queue<P> q;
    vector<vector<P>> adj(nodes + 1);
    vector<int> parent(nodes + 1, -1);
    vector<int> dist(nodes + 1, INT_MAX);

    for(int i = 0;i < edges; i += 1){
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dist[src] = 0;
    parent[src] = src;
    q.push({src, 0});

    while(!q.empty()){
        int currNode = q.front().first;
        int currDist = q.front().second;
        q.pop();

        for(auto& it:adj[currNode]){
            int nextNode = it.first;
            int nextDist = it.second;

            if(currDist + nextDist < dist[nextNode]){
                dist[nextNode] = currDist + nextDist;
                parent[nextNode] = currNode;
                q.push({nextNode, dist[nextNode]});
            }
        }
    }

    return dist;
}