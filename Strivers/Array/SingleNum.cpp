#include <bits/stdc++.h>
using namespace std;

// brute
int singleNumber(vector<int>& nums) {
    for(int i=0;i<nums.size();i++){
        int cnt = 0;
        for(int j=0;j<nums.size();j++){
            if(nums[i] == nums[j]) cnt++;
        }
        if(cnt != 2) return nums[i];
    }
    return -1;
}

int singleNumber_(vector<int>& nums) {
    unordered_map<int, int> hash;
    for(int i = 0;i<nums.size();i++){
        hash[nums[i]]++;
    }
     for(auto it : hash) {
        if(it.second == 1) {
            return it.first;
        }
    }
    return -1;
}

int singleNumber__(vector<int>& nums) {
    int res = nums[0];
    for(int i=1;i<nums.size();i++){
        res ^= nums[i];
    }
    return res;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout<<singleNumber(nums)<<"\n";
    cout<<singleNumber_(nums)<<"\n";
    cout<<singleNumber__(nums)<<"\n";
    return 0;
}