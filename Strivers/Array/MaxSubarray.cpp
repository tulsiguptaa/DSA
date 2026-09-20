#include <bits/stdc++.h>
using namespace std;

// Brtue 
int maxSubArray(vector<int>& nums) {
    int maxi = nums[0];
    for(int i=0;i<nums.size();i++){
        int sum = 0;
        for(int j=i+1;j<nums.size();j++){
            sum += nums[j];
            maxi = max(sum, maxi);
        }
    }   
    return maxi;   
}

// Optimal 
int maxSubArray_(vector<int>& nums) {
    int sum = 0;
    int maxi = MIN_INT;
      for(int i=0;i<nums.size();i++){
        sum += nums[i];
        if(sum>maxi) maxi = sum;
        if(sum<0) sum = 0;
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

    // cout<<maxSubArray(nums);

    cout<<maxSubArray_(nums);


    return 0;
}