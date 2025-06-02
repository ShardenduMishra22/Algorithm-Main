#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st, int currNode) {
    visited[currNode] = true;

    for(int neighbour : adj[currNode]) {
        if(!visited[neighbour]) {
            dfs(adj, visited, st, neighbour);
        }
    }

    st.push(currNode);
}

vector<int> topologicalSort(vector< vector<int> > &edges,int numberNodes,int numberEdges){
    vector<vector<int>> adj(numberNodes + 1);

    for(int i = 0; i < numberEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    stack<int> st;
    vector<int> solution;
    vector<bool> visited(numberNodes + 1, false);

    for(int i=1;i<numberNodes;i++){
        if(visited[i]) continue;

        dfs(adj, visited, st, i);
    }

    while(!st.empty()) {
        solution.push_back(st.top());
        st.pop();
    }

    return solution;
}