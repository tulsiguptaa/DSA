#include <bits/stdc++.h>
using namespace std;

// Time complexity = O(n^2)
// Space complexity = O(n)
// It is a unstable sorting

int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void QuickSort(int arr[],int low,int high){
  // base case 
  
  if(low>=high){
    return;
  }
  int pi = partition(arr,low,high);
  QuickSort(arr,low,pi-1);
  QuickSort(arr,pi+1,high);

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
   QuickSort(arr,0,n-1);
   cout<<"The sorted array is:";
   for(int i=0;i<n;i++){
    cout<<" ";
    cout<<arr[i];
   }
    return 0;
}