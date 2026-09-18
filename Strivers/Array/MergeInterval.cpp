#include <bits/stdc++.h>
using namespace std;

// Optimal
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout<<merge(nums);
    

    return 0;
}