#include <bits/stdc++.h>
using namespace std;

//Brute
bool containsDuplicate(vector<int>& nums) {
       for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i] == nums[j]) return true;
        }
       } 
       return false;
}

//Better
bool containsDuplicate_(vector<int>& nums){
    int hash[10] = {0};
    for(int i=0;i<nums.size();i++){
        hash[nums[i]] ++;
    }
    for(int i=0;i<10;i++){
        if(hash[i] == 2) return true;
    }
    return false;
}

//Optimal 
bool containsDuplicate__(vector<int>& nums){
    unordered_set<int> st;

        for (int num : nums) {
            if (st.find(num) != st.end()) {
                return true;
            }
            st.insert(num);
        }
         return false;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout<<containsDuplicate(nums);
    cout<<containsDuplicate_(nums);
    cout<<containsDuplicate__(nums);
    return 0;
}