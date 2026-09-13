#include <bits/stdc++.h>
using namespace std;

// Brute force

vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }

// Optimal

vector<int> twoSum_(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;
       for(int i = 0; i < nums.size(); i++) {
        int required = target - nums[i];

        if(mpp.find(required) != mpp.end()) {
            return {mpp[required], i};
        }

        mpp[nums[i]] = i;
    }
        return {-1,-1};
}
int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Brute
    vector<int> ans = twoSum(nums, 5);
    cout << ans[0] << " " << ans[1]<<"\n";

    // Optimal
    vector<int> ans1 = twoSum_(nums, 5);
    cout << ans1[0] << " " << ans1[1];
    return 0;
}