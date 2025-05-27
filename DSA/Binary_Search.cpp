#include <bits/stdc++.h>
using namespace std;

// --------binary search - time complexity = O(logn)
int binarySearch(int arr[],int n,int key){
    sort(arr,arr+n);
    int low = 0;
    int high = n-1;
    while(low<=high){
        int  mid = (low + high)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid]>key){
            high = mid-1;
        }
        else{
            low = mid+1 ;
        }
    }
    return -1;
}

// --------- using recursion
int binarySearch_(int arr[],int low,int high,int key){
    int mid = (low+high)/2;
    if(low>high) return -1;
    if(arr[mid] == key){
        return mid;
    }
    else if(arr[mid] > key){
        binarySearch_(arr,low,mid-1,key);
    }
    else{
        binarySearch_(arr,mid+1,high,key);
    }
}


int main() {
    int arr[20],n;
    cout<<"Enter the size of array:";
    cin>>n;
    cout<<"Enter the element of sorted array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the element to search in array:";
    cin>>key;
    cout<<"The index at which target is found is:"<<binarySearch(arr,n,key)<<endl;
    cout<<"The index at which target is found using recursion is:"<<binarySearch_(arr,0,n-1,key)<<endl;
    // built in function -- it is a boolean function
    cout<<"Is the key present "<<binary_search(arr,arr+n,key);

    return 0;
}