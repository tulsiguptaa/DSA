#include <bits/stdc++.h>
using namespace std;

// Brute 
int missingNumber(vector<int>& nums) {
     for(int i=0;i<=nums.size();i++) {
        bool check = false;
        for(int j=0;j<nums.size();j++){
            if(nums[j] == i) check = true;

        }
        if(check == false) return i;
     } 
     return -1;
}

// optimal
int missingNumber_(vector<int>& nums) {
    int res = 0;
    for(int i=1;i<=nums.size();i++){
        res ^= i;
    }
    for(int i=0;i<nums.size();i++){
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

    cout<<missingNumber(nums)<<"\n";
    cout<<missingNumber_(nums)<<"\n";
    return 0;
}