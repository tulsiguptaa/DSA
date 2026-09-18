#include <bits/stdc++.h>
using namespace std;

// Brute 
void Sort012(vector<int>& arr, int n){
    sort(arr.begin(), arr.end());
}

// Better
void Sort012_(vector<int>& arr, int n){
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 0) cnt0 ++;
        else if(arr[i] == 1) cnt1++;
        else cnt2++;
    }
    for(int i=0;i<cnt0;i++) arr[i] = 0;
    for(int i=cnt0;i<cnt1+cnt0;i++) arr[i] = 1;
    for(int i=cnt1+cnt0;i<n;i++) arr[i] = 2;
    
}

// Optimal
void Sort012__(vector<int>& arr, int n){
    int low = 0;
    int high = n-1;
    int mid = 0;
    while(mid<=high){
        if(arr[mid] == 0) {
            swap(arr[mid], arr[low]);
            low++;
            mid++:
        }
        if(arr[mid] == 2) {
            swap(arr[mid], arr[high]);
            high --;
        }
        if(arr[mid] == 1) mid++;
        
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

    // Brute 

    // Sort012(nums,n);
    // for(int i = 0; i < n; i++) {
    //     cout << nums[i];
    // }

    // Better
    // Sort012_(nums,n);
    // for(int i = 0; i < n; i++) {
    //     cout << nums[i];
    // }

    // Optimal
    Sort012_(nums,n);
    for(int i = 0; i < n; i++) {
        cout << nums[i];
    }

    return 0;
}