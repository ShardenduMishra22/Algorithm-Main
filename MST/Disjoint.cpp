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
