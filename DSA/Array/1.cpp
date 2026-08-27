#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cout<<"Enter the value of m:";
    cin>>m;
    int arr1[m];
    for(int i=0;i<m;i++){
        cin>>arr1[i];
    }
    int temp[n+m];
    int k = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i] == arr1[j] && temp[k-1] != arr[i]){
                temp[k] = arr[i];
                k++;
            }
        }
    }
    // result
    for(int i=0;i<k;i++){
        cout<<temp[i]<<" ";
    }
    return 0;
}