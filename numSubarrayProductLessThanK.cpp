#include <bits/stdc++.h>
using namespace std;

 int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long mul = 1;
            for (int j = i; j < nums.size(); j++) {
                mul *= nums[j];
                if (mul < k) {
                    res++;
                } else {
                    break;
                }
            }
        }
        return res;
}

 int numSubarrayProductLessThanK_(vector<int>& nums, int k) {
    if (k <= 1) return 0;
    int l = 0;
    int r = 0;
    long long mul = 1;
    int res = 0;
    while(r<nums.size()){
        mul *= nums[r];
        while (mul >= k) {
            mul /= nums[l];
            l++;
        }
        res += (r - l + 1);
        r++;
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

    // cout<<numSubarrayProductLessThanK(nums, 100);
    cout<<numSubarrayProductLessThanK_(nums, 100);
    return 0;
}