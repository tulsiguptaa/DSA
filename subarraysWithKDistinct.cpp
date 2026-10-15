#include <bits/stdc++.h>
using namespace std;

int subarraysWithKDistinct(vector<int>& nums, int k) {
    int cnt = 0;
    set<int> st;
    vecto<vector<<int>> ans;
    for(int i=0;i<nums.size();i++){
        st.push(nums[i]);
        if(st.size() == k){
            int top = 
            ans.push_back(nums[i])
        }
    }
}


int atMostK(vector<int>& nums, int k) {
    int l = 0, cnt = 0;
    int ans = 0;
    unordered_map<int, int> freq;

    for (int r = 0; r < nums.size(); r++) {
        if (freq[nums[r]] == 0) {
            cnt++;
        }
        freq[nums[r]]++;

        while (cnt > k) {
            freq[nums[l]]--;

            if (freq[nums[l]] == 0) {
                cnt--;
            }
            l++;
        }

        ans += r - l + 1;
    }

    return ans;
}

int subarraysWithKDistinct_(vector<int>& nums, int k) {
    return atMostK(nums, k) - atMostK(nums, k - 1);
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
    return 0;
}