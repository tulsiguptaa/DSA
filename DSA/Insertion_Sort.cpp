#include <bits/stdc++.h>
using namespace std;

// Repeatedly take the element from unsorted array and insert in sorted array at correct position
//Time Complexity = O(n^2) - best time complexity = O(N)
// Space complexity = O(1)
// It is stable sorting

void InsertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int j = i-1;
        int current = arr[i];
        // finding the correct position of the current element
        while(j>=0 && arr[j]>current){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
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
   InsertionSort(arr,n);
   cout<<"The sorted array is:";
   for(int i=0;i<n;i++){
    cout<<" ";
    cout<<arr[i];
   }
    return 0;
}