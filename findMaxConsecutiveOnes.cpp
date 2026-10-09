#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxi = 0;
    for(int i=0;i<nums.size();i++){
        int cnt = 0;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j] == 1){
                cnt++;
                maxi = max(maxi, cnt);
            }
            if(nums[j] == 0){
                cnt = 0;
            }
        }
    } 
    return maxi;       
}

int findMaxConsecutiveOnes_(vector<int>& nums) {
    int maxi = 0;
    stack<int> st;
    for(int i=0;i<nums.size();i++){
        int cnt = 0;
        if(nums[i] == 1){
            st.push(nums[i]);
        }
        if(nums[i] == 0){
            while(!st.empty()){
                cnt++;
                st.pop();
            }
            maxi = max(maxi, cnt);
        }
    } 

    maxi = max(maxi, (int)st.size());
    return maxi;       
}

int findMaxConsecutiveOnes__(vector<int>& nums) {
    int maxi = 0;
    int cnt = 0;
    for(int i=0;i<nums.size();i++){
      if(nums[i] == 1){
        cnt ++;
        maxi = max(maxi, cnt);
      } 
      else{
        cnt = 0;
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

    cout<<findMaxConsecutiveOnes_(nums);
    return 0;
}