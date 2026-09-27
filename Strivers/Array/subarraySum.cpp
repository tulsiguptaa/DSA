#include <bits/stdc++.h>
using namespace std;

// brute force
int subarraySum(vector<int>& nums, int k) {
    int cnt = 0;
    for(int i=0;i<nums.size();i++){
        int sum = 0;
        for(int j=i;j<nums.size();j++){
            sum += nums[j];
            if(sum == k) cnt++;
        }
    }
    return cnt;
}

// optimal
int subarraySum_(vector<int>& nums, int k) {
  unordered_map<int, int> mp;

    mp[0] = 1;

    int sum = 0;
    int cnt = 0;

    for (int num : nums) {
        sum += num;

        if (mp.find(sum - k) != mp.end()) {
            cnt += mp[sum - k];
        }

        mp[sum]++;
    }

    return cnt;
}


int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout<<subarraySum(nums, 3)<<"\n";
    cout<<subarraySum_(nums, 3);

    return 0;
}