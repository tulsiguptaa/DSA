#include <bits/stdc++.h>
using namespace std;

// Brute force 
vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k] == 0) ans.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return ans;
}

// Optimal


int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Brtue
    vector<vector<int>> ans = threeSum(nums);

    for(auto triplet : ans) {
    cout << "[ ";

    for(auto x : triplet) {
        cout << x << " ";
    }

    cout << "] ";
}

    // Optimal
    // cout<<threeSum_(nums);
    return 0;
}