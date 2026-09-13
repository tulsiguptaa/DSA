#include <bits/stdc++.h>
using namespace std;


bool search(int arr[], int n, int target){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] > arr[low] ){
            ans = 
            low = mid + 1;
        }
        else{

        }
    }
}


class LRU{
    int capacity;
    Node* next; Node* prev;
    Node* head; Node* tail; map<int, Node*> mpp;
    LRU(int cap){
        capacity = cap;
        head->next = tail;
        tail->prev = head;
        head->prev = nullptr;
        tail->next = nullptr;
    }
    int get(key){
        Node* temp = mpp.second;

        return temp->val;
    }
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