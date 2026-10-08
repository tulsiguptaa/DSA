#include <bits/stdc++.h>
using namespace std;


long long maximumSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();

    long long sum = 0;
    long long maxi = 0;

    unordered_set<int> st;

    int i = 0;

    for (int j = 0; j < n; j++) {
        while (st.count(nums[j])) {
            sum -= nums[i];
            st.erase(nums[i]);
            i++;
        }

        sum += nums[j];
        st.insert(nums[j]);

        if (j - i + 1 > k) {
            sum -= nums[i];
            st.erase(nums[i]);
            i++;
        }

        if (j - i + 1 == k) {
            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int k;
    cout<<"Enter the val of k: ";
    cin>>k;


    cout<< maximumSubarraySum(nums, k);
    
    return 0;
}