#include<bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>>& dist){
    int n = dist.size();

    for(int k = 0;k < n;k += 1){
        for(int i = 0;i < n;i += 1){
            for(int j = 0;j < n;j += 1){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for(int i = 0;i < n;i += 1){
        if(dist[i][i] < 0){
            cout << "Negative weight cycle detected!" << endl;
            return;
        }
    }
    
    cout << "No negative weight cycle detected." << endl;
}