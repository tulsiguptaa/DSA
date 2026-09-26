#include <bits/stdc++.h>
using namespace std;

// brute force
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();  
    int n = matrix[0].size(); 
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == target) return true;
        }
    }
    return false;
}

// optimal
bool searchMatrix_(vector<vector<int>>& matrix, int target) {
     int m = matrix.size();  
    int n = matrix[0].size(); 
    int low = 0;
    int high = n*m-1;
    while(low<=high){
        int mid = low + (high - low) / 2;
        if(matrix[mid/n][mid%n] == target) return true;
        else if(matrix[mid/n][mid%n] > target) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}

int main() { 
    int n, m;
    cout<<"Enter the val of n and m: ";
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                 cin >> matrix[i][j];
    }
}

    cout<<searchMatrix(matrix, 4);
    cout<<searchMatrix_(matrix, 4);
    return 0;
}