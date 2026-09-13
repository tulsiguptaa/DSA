#include <bits/stdc++.h>
using namespace std;

// Brute force
int maxArea(vector<int>& height) {
        int n = height.size();
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               int cap = (j-i)  * min(height[j], height[i]);
                res = max(res, cap);
            }
        }
        return res;
}

// Optimal
int maxArea_(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int maxi = 0;
        while(l<r){
            int cap = (r-l)  * min(height[l], height[r]);
            maxi = max(maxi, cap);
            if(height[l] < height[r]) l++;
            else r--;
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

    // Brtue
    cout<<maxArea(nums)<<"\n";

    // Optimal
    cout<<maxArea_(nums);

    return 0;
}