#include <bits/stdc++.h>
using namespace std;

// Brute force
int findDuplicate(vector<int>& nums) {
           for (int i = 1; i <= nums.size() - 1; i++) {
        int count = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == i)
                count++;
        }

        if (count > 1)
            return i;
    }

    return -1;
    }

// Optimal
int findDuplicate_(vector<int>& nums) {
    vector<int> freq(nums.size(), 0);

    for (int x : nums) {
        freq[x]++;

        if (freq[x] > 1)
            return x;
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout<<findDuplicate(nums);
    cout<<findDuplicate_(nums);
    

    return 0;
}