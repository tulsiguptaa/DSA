#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int l = 0;
    int r = 0;
    deque<int> dq;
    vector<int> ans;

    while (r < nums.size()) {
        while (!dq.empty() && nums[dq.back()] < nums[r]) {
            dq.pop_back();
        }
        dq.push_back(r);
        if (dq.front() < l) {
            dq.pop_front();
        }
        if (r - l + 1 == k) {
            ans.push_back(nums[dq.front()]);
            l++;
        }
        r++;
    }
    return ans;
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

    vector<int> ans = maxSlidingWindow(nums, k);
    for(int i = 0; i < n; i++) {
        cout<< nums[i];
    }
    return 0;
}