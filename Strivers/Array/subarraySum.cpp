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


int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout<<subarraySum(nums, 3);

    return 0;
}