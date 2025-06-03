#include<bits/stdc++.h>
using namespace std;

using P = pair<int, int>;

vector< pair<P,int> > calculatePrimsMST(vector< vector<int> > &edge,int edges, int nodes){
    vector<vector<P>> adj(nodes + 1);

    for(int i=0;i<edges;i++){
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> parent(nodes + 1, -1);
    vector<int> key(nodes + 1, INT_MAX);
    vector<bool> inMST(nodes + 1, false);

    
}