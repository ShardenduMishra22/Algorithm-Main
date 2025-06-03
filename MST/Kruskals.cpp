#include<bits/stdc++.h>
using namespace std;

int findParent(int node,vector<int> &parent){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent[node], parent);
}

void Union(int x, int y, vector<int> &parent, vector<int> &rank) {
    int xParent = findParent(x, parent);
    int yParent = findParent(y, parent);

    if (xParent == yParent)
        return;

    if (rank[xParent] > rank[yParent]) {
        parent[yParent] = xParent;
    } else if (rank[xParent] < rank[yParent]) {
        parent[xParent] = yParent;
    } else {
        parent[xParent] = yParent;
        rank[yParent]++;
    }
}

int kruskals(int n,vector<vector<int>> &edges){
    sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    });

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    int cost = 0;
    for(auto& edge:edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        int uParent = findParent(u, parent);
        int vParent = findParent(v, parent);

        if(uParent != vParent){
            cost += w;
            Union(u, v, parent, rank);
        }
    }

    return cost;
}   