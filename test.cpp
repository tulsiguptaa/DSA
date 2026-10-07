#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
    int n = grid.size();
    int m = grid[0].size();
    if(i<0 || i>n-1 || j<0 || j>m-1) return ;
    dfs(i+1, j, grid, vis);
    dfs(i-1, j, grid, vis);
    dfs(i, j+1, grid, vis);
    dfs(i, j-1, grid, vis);
}

int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m,0));
    for(int i = 0; i<n;i++){
        if(grid[i][0] == 1){
            dfs(i,0,grid);
            vis[i][0] = 1;
        }
        if(grid[i][m-1] == 1){
            dfs(i,0,grid);
            vis[i][0] = 1;
        }
    }
    for(int i = 0; i<m;i++){
        if(grid[0][i] == 1){
            dfs(i,0,grid);
            vis[0][i] = 1;
        }
        if(grid[n-1][i] == 1){
            dfs(i,0,grid);
            vis[n-1][i] = 1;
        }
    }
    int cnt = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j] == 1){
                cnt++; 
            }
        }
    }
    return cnt;
}

int main() {
    
    return 0;
}