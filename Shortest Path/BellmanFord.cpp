#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &edge, int nodes, int edges, int src){
    vector<int> dist(nodes+1,INT_MAX);
    dist[src] = 0;

    for(int j = 0; j < nodes - 1; j++){
        for(int i=0;i<edges;i++){
            int u = edge[i][0];
            int v = edge[i][1];
            int w = edge[i][2];
    
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int i=0;i<edges;i++){
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];

        if(dist[u] + w < dist[v]){
            cout << "Negative weight cycle detected!" << endl;
            return {};
        }
    }

    return dist;
}