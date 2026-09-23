#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < target){
            low = mid + 1;
        }   
        else {
            high = mid - 1;
        }
    }  
    return low; 
}


int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout<<searchInsert(nums, 5);

    return 0;
}