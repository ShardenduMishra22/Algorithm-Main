#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfsArticulation(int u, int parent, vector<vector<int>>& adj,
                         vector<bool>& visited, vector<int>& tin, vector<int>& low,
                         int& timer, vector<bool>& isArticulation) {

        visited[u] = true;
        tin[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;
            if (visited[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfsArticulation(v, u, adj, visited, tin, low, timer, isArticulation);
                low[u] = min(low[u], low[v]);
                if (low[v] >= tin[u] && parent != -1)
                    isArticulation[u] = true;
                children++;
            }
        }

        if (parent == -1 && children > 1)
            isArticulation[u] = true;
    }

    vector<int> findArticulationPoints(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> tin(n, -1), low(n, -1);
        vector<bool> isArticulation(n, false);
        int timer = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfsArticulation(i, -1, adj, visited, tin, low, timer, isArticulation);
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (isArticulation[i]) result.push_back(i);
        }

        return result;
    }
};
