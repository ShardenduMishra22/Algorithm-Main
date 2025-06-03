#include <bits/stdc++.h>
using namespace std;

void dfs1(int u, vector<vector<int>>& g, vector<bool>& vis, stack<int>& st) {
    vis[u] = true;
    for (int v : g[u])
        if (!vis[v])
            dfs1(v, g, vis, st);
    st.push(u);
}

void dfs2(int u, vector<vector<int>>& rg, vector<bool>& vis, vector<int>& comp) {
    vis[u] = true;
    comp.push_back(u);
    for (int v : rg[u])
        if (!vis[v])
            dfs2(v, rg, vis, comp);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n), rg(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    stack<int> st;

    vector<bool> vis(n, false);
    for (int i = 0; i < n; ++i){
        if (!vis[i]){
            dfs1(i, g, vis, st);
        }
    }

    fill(vis.begin(), vis.end(), false);
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (!vis[u]) {
            vector<int> comp;
            dfs2(u, rg, vis, comp);
            for (int x : comp){
                cout << x << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
