#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfsBridge(int u, int parent, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& tin, vector<int>& low, int& timer, vector<pair<int, int>>& bridges) {

        visited[u] = true;
        tin[u] = low[u] = timer++;

        for (int v : adj[u]) {
            if (v == parent) continue;
            if (visited[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfsBridge(v, u, adj, visited, tin, low, timer, bridges);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]){
                    bridges.push_back({u, v});
                }
            }
        }
    }

    vector<pair<int, int>> findBridges(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<pair<int, int>> bridges;
        vector<bool> visited(n, false);
        vector<int> tin(n, -1), low(n, -1);
        int timer = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfsBridge(i, -1, adj, visited, tin, low, timer, bridges);
            }
        }

        return bridges;
    }
};
