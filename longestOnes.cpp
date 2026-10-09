#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int maxi = 0; 
    for(int i=0;i<nums.size();i++){
        int cnt = 0;
        int p = k;
          for (int j = i; j < nums.size(); j++) {
            if (nums[j] == 1) {
                cnt++;
            }
            else if (p > 0) {
                cnt++;
                p--;
            }
            else {
                break;
            }

            maxi = max(maxi, cnt);
        }
    }

    return maxi;
}

int longestOnes_(vector<int>& nums, int k) {
   int maxi = 0;
    int n = nums.size();
    int i = 0, j = 0;
    int p = k;
    int cnt = 0;

    while (j < n) {
        if (nums[j] == 1) {
            cnt++;
        }
        else if (p > 0) {
            cnt++;
            p--;
        }
        else {
            while (p == 0) {
                if (nums[i] == 0) {
                    p++;
                }
                i++;
                cnt--;
            }
            continue;
        }

        maxi = max(maxi, cnt);
        j++;
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

    cout<<longestOnes(nums, 3);
    cout<<longestOnes_(nums, 3);
    return 0;
}