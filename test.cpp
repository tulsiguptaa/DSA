#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> vis[], vector<int> path[], vector<int> adj[]){
    for(auto it: adj){
        if(vis[it] == 0){
            dfs(vis, path, adj);
            path[it] = 1;
            vis[it] = 1;
        }
    }
}

bool isCyclic(int V, vector<int> adj[]){
    vector<int> vis(V, 0);
    vector<int> path(V, 0);
    for(int i=1;i<=V;i++){
        if(vis[i] == 0){
            if(dfs(vis, path, adj) == true) return true;
        }
    }
    return false;
}

int main() {
    
    return 0;
}