#include <bits/stdc++.h>
using namespace std;

// brute force
void sortColors(vector<int>& nums) {
    sort(nums.begin(), nums.end());
}

// better 
void sortColors_(vector<int>& nums) {
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] == 0) cnt0 ++;
        else if(nums[i] == 1) cnt1++;
        else cnt2++;
    }
    for(int i=0;i<cnt0;i++) nums[i] = 0;
    for(int i=cnt0;i<cnt1+cnt0;i++) nums[i] = 1;
    for(int i=cnt1+cnt0;i<nums.size();i++) nums[i] = 2;      
}

// optimal
void sortColors__(vector<int>& nums) {
 int low = 0;
    int high = nums.size()-1;
    int mid = 0;
    while(mid<=high){
        if(nums[mid] == 0) {
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid] == 2) {
            swap(nums[mid], nums[high]);
            high --;
        }
        if(nums[mid] == 1) mid++;
        
    }
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sortColors(nums);
    for(int i = 0; i < n; i++) {
        cout<< nums[i]<<" ";
    }

    sortColors_(nums);
    for(int i = 0; i < n; i++) {
        cout<< nums[i]<<" ";
    }
    sortColors__(nums);
    for(int i = 0; i < n; i++) {
        cout<< nums[i]<<" ";
    }

    return 0;
}