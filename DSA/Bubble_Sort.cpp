#include <iostream>
using namespace std;

//--------------Repeatedly swap with adjacent--------------
// Worst case - when all elements are in decreasing order O(n^2)
// Bubble sort is a stable sort in which the position of the same element does not swap

// No of swap = n(n-1)/2
// Time complexity = O(n^2)  best time complexity = O(N)
// Space complexity = O(1)

void BubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        // Optimizing bubble sort
        bool flag = false; 
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                flag = true;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(flag!=true){
            break;
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
   BubbleSort(arr,n);
   cout<<"The sorted array is:";
   for(int i=0;i<n;i++){
    cout<<" ";
    cout<<arr[i];
   }
    return 0;
}