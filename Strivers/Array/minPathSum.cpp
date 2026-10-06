#include <bits/stdc++.h>
using namespace std;

int find(int i, int j,vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    if (i == n - 1 && j == m - 1)
        return grid[i][j];

    if (i >= n || j >= m)
        return INT_MAX;

    int right = find(i, j + 1, grid);
    int down = find(i + 1, j, grid);

    return grid[i][j] + min(right, down);
}


int minPathSum(vector<vector<int>>& grid) {
    return find(0, 0, grid);
}
int main() {
    vector<vector<int>> grid = {
    {1, 3, 1},
    {1, 5, 1},
    {4, 2, 1}
};
    cout<<minPathSum(grid);
    return 0;
}