#include <bits/stdc++.h>
using namespace std;

// brute force
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans(nums.size());
    for(int i=0;i<nums.size();i++){
        int prod = 1;
        for(int j=0;j<nums.size();j++){
            if(i!=j) {
                prod = prod * nums[j];
            }
            ans[i] = prod;
        }
    }
    return ans;
}

// optimal
vector<int> productExceptSelf_(vector<int>& nums) {
    vector<int> ans(nums.size());
    int prod = 1;
    for(int i=0;i<nums.size();i++){
        prod *= nums[i];
    }
    for(int i=0;i<nums.size();i++){
        ans[i] = prod / nums[i];
    }
    return ans;
}


vector<int> productExceptSelf__(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);

    int prefix = 1;

    for(int i = 0; i < n; i++) {
        ans[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;

    for(int i = n - 1; i >= 0; i--) {
        ans[i] *= suffix;
        suffix *= nums[i];
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int>ans = productExceptSelf(nums);
    for(int i=0;i<nums.size();i++){
        cout<<ans[i]<<" ";
    }


    vector<int>ans1 = productExceptSelf_(nums);
    for(int i=0;i<nums.size();i++){
        cout<<ans1[i]<<" ";
    }
    vector<int>ans2 = productExceptSelf__(nums);
    for(int i=0;i<nums.size();i++){
        cout<<ans2[i]<<" ";
    }
    return 0;
}