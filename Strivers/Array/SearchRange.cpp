#include <bits/stdc++.h>
using namespace std;

// Optimal
vector<int> searchRange(vector<int>& nums, int target) {
        auto lb = lower_bound(nums.begin(), nums.end(), target);

        if (lb == nums.end() || *lb != target)
            return {-1, -1};

        auto ub = upper_bound(nums.begin(), nums.end(), target);

        int first = lb - nums.begin();
        int last = ub - nums.begin() - 1;

        return {first, last};
    }


int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Brtue
    vector<int> ans = searchRange(nums, 8);
    // cout<<ans.first<<" "<<ans.second;
    cout<<ans[0]<<" "<<ans[1];
    

    return 0;
}