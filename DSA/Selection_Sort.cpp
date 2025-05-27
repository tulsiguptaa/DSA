#include <bits/stdc++.h>
using namespace std;

//--------------Find minimum element in unsorted array---------
// Time complexity = O(n^2) 
// Space complexity = O(1)
// It is an unstable sorting

// This is somehow opposite of bubble sort- in bubble sort the largest element is placed at the end and in selection sort the smallest element is placed at the begenning 

void SelectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_index = i;

        // finding the minimum element in array
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
        }

        // swapping the minimum element
        if(i!=min_index){
            int temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp; 
        }
    }
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
   SelectionSort(arr,n);
   cout<<"The sorted array is:";
   for(int i=0;i<n;i++){
    cout<<" ";
    cout<<arr[i];
   }
    return 0;
}