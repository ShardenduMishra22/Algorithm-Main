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
    void solve(vector<int>& ans, vector<bool>& visited, int currNode, vector<vector<int>> &adj) {
        if(visited[currNode]) return;

        queue<int> relatedNodes;
        relatedNodes.push(currNode);
        visited[currNode] = true;

        while(!relatedNodes.empty()) {
            int curr = relatedNodes.front();
            relatedNodes.pop();
            ans.push_back(curr);

            for(int& newNode : adj[curr]) {
                if(!visited[newNode]) {
                    visited[newNode] = true;
                    relatedNodes.push(newNode);
                }
            }
        }
    }

    vector<int> bfs(vector<vector<int>> &adj) {
        int numberOfNodes = adj.size();
        vector<int> ans;
        vector<bool> visited(numberOfNodes, false);

        for(int i = 0; i < numberOfNodes; i++) {
            solve(ans, visited, i, adj);
        }

        return ans;
    }
};