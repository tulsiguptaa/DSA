#include <bits/stdc++.h>
using namespace std;


int search(int arr[], int n, int target){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid] = target){
           return arr[mid];
        }
        else if(arr[mid] > target){
            high = low - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}
int main() {
    int n;
    cout<<"Enter the val of n: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the ele of array: ";
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    cout<<search(arr,n,5);
    return 0;
}