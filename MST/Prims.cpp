#include<bits/stdc++.h>
using namespace std;

using p = pair<int, int>;
using P = pair<p,int>;  // neighbour_weight node parent

int calculatePrimsMST(vector< vector<int> > &edge,int edges, int nodes){
    vector<vector<p>> adj(nodes + 1);

    for(int i=0;i<edges;i++){
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({{0,0},-1});

    int sum = 0;

    vector<int> parent(nodes + 1, -1);
    vector<bool> inMST(nodes + 1, false);

    while(!pq.empty()){
        auto tp = pq.top();
        pq.pop();

        int par = tp.second;
        int wt = tp.first.first;
        int node = tp.first.second;

        if(inMST[node]){
            continue;
        }

        inMST[node] = true;
        sum += wt;
        parent[node] = par;

        for(auto& it:adj[node]){
            int neighbour = it.first;
            int neighbour_weight = it.second;

            if(!inMST[neighbour]){
                pq.push({{neighbour_weight, neighbour}, node});
            }
        }
    }

    return sum;
}