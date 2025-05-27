#include <bits/stdc++.h>
using namespace std;

// Time Complexity = O(nlogn)
// Space Complexity = O(n)
// It is stable sorting

void Merge(int arr[],int low,int mid,int high){
    int an = mid-low+1;
    int bn = high-mid;
    // Temperary array
    int a[an];
    int b[bn];
    for(int i=0;i<an;i++){
        a[i] = arr[low+i];
    }
    for(int j=0;j<bn;j++){
        b[j] = arr[mid+1+j];
    }


    // p is pointing to temporary array a and q is pointing to temporary array b
    int p=0,q=0;
    int k=low;
    while(p<an && q<bn){
        if(a[p]<=b[q]){
            arr[k] = a[p];
            p++;
        }
        else{
            arr[k] = b[q];
            q++;    
        }
        k++;
    }

    while(p<an){
        arr[k] = a[p];
        k++;
        p++;
    }

    while(q<bn){
        arr[k] = b[q];
        k++;
        q++;
    }
}

void MergeSort(int arr[],int low,int high){
    int mid = (low+high)/2;
    // base case
    if(low>=high){
        return;
    }
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    Merge(arr,low,mid,high);
}


int main() {
   int n;
   cout<<"Enter the size of array: ";
   cin>>n;
   int arr[n];
   cout<<"Enter the values:";
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   MergeSort(arr,0,n-1);
   cout<<"The sorted array is:";
   for(int i=0;i<n;i++){
    cout<<" ";
    cout<<arr[i];
   }
    return 0;
}