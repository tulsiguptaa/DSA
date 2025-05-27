#include <bits/stdc++.h>
using namespace std;

// ----------------------segmentation fault or stack overflow - when the stack is full / out of memory

// -------------print num from 1 to n
void fun(int i,int n){
    // base case
    if(i<1){
        return;
    }
    cout<<i<<" ";
    fun(i-1,n);
}

// ----------A great difference in these two function,,both are almost same ,,but the second function prints the value of i after the function call means baktracking

// -----------backtracking
void print(int i,int n){
    if(i<1){
        return;
    }
    print(i-1,n);
    cout<<i<<" ";
}

// ------------print name five times
void printName(int i, string name){
    if(i<1) return;
    cout<<name<<endl;
    printName(i-1,name);
}

// --------------sum of first n num using paramatersid recursion
void sum(int i, int total){
    if(i<1){
       cout<<total;
       return;
    }
    sum(i-1,total+i);
}

// --------------sum of first n num using functional recursion
int PrintSum(int n){
    if(n<=0){
        return 0;
    }
    return n + PrintSum(n-1);
}

// --------------factorial
int factorial(int n){
    if(n == 0) return 1;
    return n * factorial(n-1);
}

// -------------reverse an array
void ReverseArray(int arr[], int n){
    if(n==0){
        return;
    }
    cout<<arr[n-1];
    ReverseArray(arr,n-1);

}

// ---------------reverse using swaping
void swap(int &a,int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void ReverseArrayBySwap(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    swap(arr[l],arr[r]);
    ReverseArrayBySwap(arr,l+1,r-1);
}

// -----------------reverse using swap but taking only one extra iterator
void ReverseArrayBySwap_(int arr[],int n, int i){
    if(i>=n/2){
        return;
    }
    swap(arr[i],arr[n-i-1]);
    ReverseArrayBySwap_(arr,n,i+1);

}

// ---------------check for palindrome
bool palindrome(char name[],int i, int n){
    if(i>=n/2){
        return true;
    }
    if(name[i]!=name[n-i-1])
    {
        return false;
    }
    palindrome(name,i+1,n);

}

// ---------------fibonacci
int fibonacci(int n){
    if(n<=1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

// ---------------print all the subsequence (subset of array)
void printSubsequences(vector<int>& arr, vector<int>& temp, int index) {
    if (index == arr.size()) {
        for (int num : temp) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    printSubsequences(arr, temp, index + 1);
    temp.push_back(arr[index]); 
    printSubsequences(arr, temp, index + 1);
    temp.pop_back();
}

// --------------- 




int main() { 
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    // fun(n,n);

    // print(n,n);

    // string name;
    // cin>>name;
    // printName(n,name);

    // sum(n,0);

    // cout<<PrintSum(n);

    // cout<<factorial(n);

    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    
    // ReverseArray(arr,n);

    // ReverseArrayBySwap(arr,0,n-1);
    
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }

    // ReverseArrayBySwap_(arr,n,0);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }

    // char name[] = "tulsi";
    // if(palindrome(name,0,5)==1){
    //     cout<<"True";
    // }
    // else{
    //     cout<<"false";
    // }
    // cout<<endl;
    // cout<<palindrome(name,0,5);

    
    // cout<<fibonacci(n);
    
    vector<int> arr = {1, 2, 3};
    vector<int> temp;
    printSubsequences(arr, temp, 0);




    return 0;
    } 