#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    void solve(vector<int>& ans,vector<bool>& visited,int& node,vector<vector<int>>& adj){
        if(visited[node]){
            return;
        }
        
        visited[node] = true;
        ans.push_back(node);
        
        for(auto& currNode : adj[node]){
            if(visited[currNode]){
                continue;
            }
            solve(ans,visited,currNode,adj);
        }
        
        return;
    }

    vector<int> dfs(vector<vector<int>>& adj){
        int node = 0;
        vector<int> ans;
        vector<bool> visited(adj.size(),false);
        
        solve(ans,visited,node,adj);
        
        return ans;
    }
};