#include <bits/stdc++.h>
using namespace std;

// <-----------pre knowledge (_) after the name of function means optimize and (__) this most much and more optimise -----------> 


// ---------remove duplicates
void removeDuplicate(int arr[],int n){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    for(int i:s){
        cout<<i<<" ";
    }
}

// ---------remove duplicates with optimisation
void removeDuplicate_(int arr[],int n){
    sort(arr,arr+n);
    int p = 0;
    for(int i=0;i<n;i++){
       if(arr[i]!= arr[p]){
        arr[p+1] = arr[i];
        p++;
       }
    }
    for(int i=0;i<p;i++){
        cout<<arr[i]<<" ";
    }
}

// ---------largest element in array
int largest(int arr[],int n){
    int largest = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    return largest;
}

// -------second largest element in array
int second_largest(int arr[],int n){
    if(n<2){
        return -1;
    }
    sort(arr,arr+n);
    for(int i=n-2;i>=0;i--){
        if(arr[i]!=arr[n-1]){
            return arr[i];
        }
    }
    return -1;
}

// --------second largest element in array with optimisation
int second_largest_(int arr[],int n){
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    int second_largest = -1;
    for(int i=0;i<n;i++){
        if(second_largest<arr[i] && arr[i]!=largest){
            second_largest = arr[i];
        }
    }
    return second_largest;
}

// --------second largest element in array with best optimisation with time complexity
int second_largest__(int arr[],int n){
    int largest_ = arr[0];
    int second_ = -1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest_){
            second_ = largest_; 
            largest_ = arr[i];
        }
        else if(arr[i]<largest_ && arr[i]>second_){
            second_ = arr[i];
        }
    }
    return second_;
}

// --------left rotate the array by one
void leftRotate(int arr[],int n){
    int temp = arr[0];
    for(int i=0;i<n-1;i++)
    {
        arr[i] = arr[i+1]; 
    }
    arr[n-1] = temp;
}

// -------left rotate by certain poistion 
void leftRotateByN(int arr[], int n, int p){
    p = p % n;  // that means if the size of array is 5 and we have to shift it 6 position it simply means 6%5 = 1 ,,,we only have to shift one position
    int temp[p];

    // copy first p elemnt in temp
    for(int i=0;i<p;i++){
        temp[i] = arr[i];
    }
     // shifting
    for(int i=0;i<n-p;i++){
        arr[i] = arr[p+i];
    
        
    }
    for(int i=n-p;i<n;i++){
        arr[i] = temp[i-(n-p)];
    }
    
}

// ----left rotate by certain but using optimisation
void leftRotateByN_(int arr[],int n, int p){
    reverse(arr,arr + p);
    reverse(arr + p,arr + n);
    reverse(arr,arr + n);
}

//  ---------moving zeroes at the end of the array
void movingZeroes(int arr[],int n){
   
    int temp[n];
    int pos = 0;
    for(int i=0;i<n;i++){
        if(arr[i]!= 0){
            temp[pos] = arr[i];
            pos++;
        }
    }
    while(pos<n){
        temp[pos] = 0;
        pos++;
    }
    for(int i=0;i<n;i++){
        arr[i] = temp[i];
    }
}

//  ---------moving zeroes at the end of the array using optimisation
void movingZeroes_(int arr[],int n){
    int j=0;
    for(int i=0;i<n;i++){
            if(arr[i] != 0){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j++;
            }
        }
}

// ---------linear search
int linearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

// ---------union of two array 
void unionArray(int arr[],int arr1[],int n,int n1){
    set<int> temp;
    for(int i=0;i<n;i++){
      temp.insert(arr[i]);
    }
    for(int i=0;i<n1;i++){
            temp.insert(arr1[i]);
    }

    for(auto i = temp.begin();i!= temp.end();i++){
        cout<<*i<<" ";
    }
}

// ---------union of two array with optimisation -- there is some issue in this code ----which i and chatgpt is unable to fix
void unionArray_(int arr[],int arr1[],int n,int n1){
    vector<int> temp;
    int i = 0,j = 0;
    while(i<n && j<n1){
        if(arr[i]<=arr1[j]){
            if(temp.empty() || temp.back()!=arr[i]){
                temp.push_back(arr[i]);
            }
            i++;
        }
        else if(arr[i] > arr1[j]){
            if(temp.empty() || temp.back()!= arr[j]){
                temp.push_back(arr[j]);
            }
            j++;
        }
        else { 
            if (temp.empty() || temp.back() != arr[i]) {
                temp.push_back(arr[i]);
            }
            i++;
            j++;
        }
    }
    while(j<n1){
        if(temp.empty() || temp.back()!= arr[j]){
            temp.push_back(arr[j]);
        }
        j++;
    }
    while(i<n){
        if(temp.empty() || temp.back()!= arr[i]){
            temp.push_back(arr[i]);
        }
        i++;
    }  
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
}

// ---------intersection of two array
void intersection(int arr[],int arr1[],int n,int n1){
    vector<int> temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n1;j++){
            if(arr[i]==arr1[j]){
                bool already = false;
               for(int k=0;k<temp.size();k++){
                if(temp[k]==arr[i]){
                    already = true;
                }
              }
               if(already == false){
                temp.push_back(arr[i]);
               }
            }
        }
    }
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
}

// --------intersection of two array with optimisation
void intersection_(int arr[],int arr1[],int n,int n1){
    unordered_set<int> temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n1;j++){
            if(arr[i]==arr1[j]){
                temp.insert(arr[i]);
            }
        }
    }
    for(const int& elem : temp) {
        cout << elem << " ";  
    }
}

// --------intersection of two array with best optimisation
void intersection__(int arr[],int arr1[],int n,int n1){
    int i=0, j=0;
    sort(arr,arr+n);
    sort(arr1,arr1+n1);
    vector<int> temp;
    while(i<n && j<n1){
        if(arr[i]<arr1[j]){
            i++;
        }
        else if(arr[i]>arr1[j]){
            j++;
        }
        else if(arr[i]==arr1[j]){
            temp.push_back(arr[i]);
            i++;
            j++;
        }
    }
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
}

// --------finding missing number from array
void missing(int arr[],int n){
    for(int i=1;i<=n;i++){
        int flag = 0;
        for(int j=0;j<n;j++){
            if(arr[j]==i){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            cout<<"The missing number is: "<<i;
        }
    }
}

// --------finding missing number from array with optimisation
void missing_(int arr[],int n){
    int hash[n+1] = {0};
    for(int i=0;i<n-1;i++){
        hash[arr[i]] ++;
    }
    for(int i=1;i<n;i++){
        if(hash[i] == 0){
            cout<<"The missing element is: "<<i;
        }
    }
}

// ---------finding missing number from array with best optimisation
void missing__(int arr[],int n){
    int sum = n*(n+1)/2;
    int s = 0;
    for(int i=0;i<n;i++){
        s += arr[i];
    }
    int mis = sum - s;
    cout<<"The missing number is: "<<mis;
}

// ---------finding missing number from array with bestest optimisation
void missing___(int arr[],int n){
    int XOR1 = 0,XOR2 = 0;
    for(int i=1;i<=n;i++){
       XOR1 = XOR1^i;
    }
       for(int i=0;i<n-1;i++){
        XOR2 = XOR2^arr[i];
       }
    cout<<"The missing number is: "<<(XOR1^XOR2);
}

// ----------maximum consecutive one in array
void consecutive(int arr[],int n){
    int count = 0;
    int maxi = 0;
    for(int i=0;i<n;i++){
            if(arr[i]==1){
                count ++;
                maxi = max(count,maxi);
            }
            else{
                count = 0;
            }
    }
    cout<<"The maximum consecutive is: "<<maxi;
}

// ----------the number which appears only once, all other comes twice
void singleNumber(int arr[],int n){
    for(int i=0;i<n;i++){
        int cnt = 0;
       int num = arr[i];
        for(int j=0;j<n;j++){
        if(arr[j] == num){
            cnt++;
        }
    }
    if(cnt == 1){
        cout<<"The single number is: "<<num<<endl;
    } 
   }
}

// ----------the number which appears only once, all other comes twice with optimisation
void singleNumber_(int arr[],int n){
    int maxi = 0;
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]);
    }
    int hash[maxi];
    for(int i=0;i<n;i++){
        hash[arr[i]] ++;
    }
    for(int i=0;i<n;i++){
        if(hash[arr[i]]== 1){
            cout<<"The single number is: "<<i;
        }
    }
}

// ----------the number which appears only once, all other comes twice with best optimisation
void singleNumber__(int arr[],int n){
    map<int, int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto i: mp){
        if(i.second == 1){
            cout<<"The single number is: "<<i.first;
        }
    }
}

// ----------the number which appears only once, all other comes twice with best optimisation
void singleNumber___(int arr[],int n){
    int XOR2 = 0;
    for(int i=0;i<n;i++){
        XOR2 = XOR2^arr[i];
    }
    cout<<"The single number is: "<<XOR2;
}

// ---------two sum
void twoSum(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
        if(arr[i] + arr[j] == target){
            cout<<"The number are: "<<arr[i]<<" and "<<arr[j];
            return;
        }
      }
    } 
    cout<<"There is no such pairs";
}

// ---------two sum with optimisation
void twoSum_(int arr[],int n,int target){
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        int a = arr[i];
        int more = target - a;
        if(mpp.find(more) != mpp.end()){
            cout<<"The numbers are: "<<more<<"and"<<a;
        }
        mpp[a] = i;
    }
}

// ----------two sum with better optimisation
void twoSum__(int arr[],int n,int target){
    sort(arr,arr+n);
    int j=n-1;
    int i = 0;
    while(i<j)
    {
        if(arr[i] + arr[j] == target){
            cout<<"The elements are: "<<arr[i]<<" and "<<arr[j];
            return;
            }
        else if(arr[i] + arr[j] > target){
            j--;
        }
        else if(arr[i] + arr[j] < target){
            i++;
        }
    }
    cout<<"Wrong target";
}

// ----------sort an array of 0's 1's and 2's
void sort0s1s2s(int arr[],int n){
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

// ------------sort an array of 0's 1's and 2's with optimisation
void sort0s1s2s_(int arr[],int n){
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            cnt0++;
        }
        else if(arr[i] == 1){
            cnt1 ++;
        }
        else if(arr[i] == 2){
            cnt2 ++;
        }
    }
    // for(int i=0;i<cnt0;i++){
    //     arr[i] = 0;
    // }
    // for(int i=cnt0;i<cnt0+cnt1;i++){
    //     arr[i] = 1;
    // }
    // for(int i=cnt0+cnt1;i<cnt2+cnt0+cnt1;i++){
    //     arr[i] = 2;
    // }
    int index = 0;
    while (cnt0--) arr[index++] = 0;
    while (cnt1--) arr[index++] = 1;
    while (cnt2--) arr[index++] = 2;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

// -----------sort an array of 0's 1's and 2's with optimisation using dutch national flag algorithm
void sort0s1s2s__(int arr[],int n){
    int low = 0;
    int high = n-1;
    int mid = 0;
    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else if(arr[mid] == 2){
             swap(arr[mid],arr[high]);
             high--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

// --------majority element in an array
int majority(int arr[],int n){
    int mid = n/2;
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(arr[j]==arr[i]){
                cnt++;
            }
        }
        if(cnt>mid){
            return arr[i];
        }
    }
    return -1;
}

// --------majority element in an array with optimisation
int majority_(int arr[],int n){
    int mid = n/2;
    map<int, int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    int maxi = 0;
    for(auto it:mp){
        if(it.second>mid){
           return it.first;
        }
    }
    return -1;
}

// --------majority element in an array with best optimisation using moore's voting algorithm
int majority__(int arr[],int n){
    int cnt = 0;
    int mid = n/2;
    int el;
    for(int i=0;i<n;i++){
        if(cnt == 0){
            cnt = 1;
            el =arr[i];
        }
        else if(arr[i] == el){
            cnt++;
        }
        else {
            cnt--;
        }
    }
    cnt = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == el){
            cnt++;
        }
    }
    if(cnt>mid){
        return el;
    }
    return -1;
}

// ---------maximum subarray sum
void maxSubarray(int arr[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<j;k++){
            sum += arr[k];
            maxi = max(maxi,sum);
            }
        }
    }
    cout<<"The maximum is: "<<maxi;
}

// ---------maximum subarray sum with optimisation
void maxSubarray_(int arr[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            maxi = max(maxi,sum);
        }
    }
    cout<<"The maximum is: "<<maxi;
}

// ---------maximum subarray sum with optimisation using kadane's algorithm
void maxSubarray__(int arr[],int n){
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum +=arr[i];
        maxi = max(sum,maxi);
        if(sum<0){
            sum = 0;
        }
    }
    cout<<"The maximum subarray sum is: "<<maxi;
}

// -----------buy and sell stock using array 
void buySellStock(int arr[],int n){
    int mini = arr[0];int profit =0;
    int cost;
    for(int i=1;i<n;i++){
        cost = arr[i] - mini;
        profit = max(profit,cost);
        mini = min(mini,arr[i]);            
        }
        cout<<"The buying is: "<<mini<<" and profit is: "<<profit;
}
   
// ----------rearrange elements by sign in array
void rearrangeBySign(int arr[],int n){
    vector<int> negative;
    vector<int> positive;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            negative.push_back(arr[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            positive.push_back(arr[i]);
        }
    }
    int j=0; int k=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            arr[i] = positive[k];
            k++;
        }
        else{
         
            arr[i] = negative[j];
            j++;
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

// ----------rearrange elements by sign in array with optimisation
void rearrangeBySign_(int arr[],int n){
    vector<int> ans(n);
    int posindex = 0;
    int negindex = 1;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            ans[negindex] = arr[i];
            negindex += 2;
        }
        else{
           ans[posindex] = arr[i];
           posindex += 2;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}

// -----------next permutation with built-in function
void permutation(int arr[],int n){
    vector<int> temp;
    for(int i=0;i<n;i++){
        temp.push_back(arr[i]);
    }
      next_permutation(temp.begin(),temp.end());
      for(auto i: temp){
        cout<<i<<" ";
      }
}

// ----------next permutation with optimisation
void permutation_(int arr[],int n){
    int idx = -1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        reverse(arr,arr+n);
    }
    else{
    for(int i=n-1;i>=idx;i--){
        if(arr[i]>arr[idx]){
            swap(arr[i],arr[idx]);
            break;
        }
    }
    reverse(arr+idx+1,arr+n);
  }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

// ----------leaders in array
void leaders(int arr[],int n){
    int leader = arr[0];
    for(int i=0;i<n;i++){
        bool test = false;
       for(int j=i+1;j<n;j++){
        if(arr[j]>arr[i]){
            test = true;
            break;  
          }
       }
       if(test== false){
        cout<<arr[i]<<" ";
       }
    }
}

// ----------leaders in array with optimisation
void leaders_(int arr[],int n){
    int maxi = INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
          cout<<arr[i]<<" ";  
        }
        maxi = max(maxi,arr[i]);
    }
}

// ----------longest consecutive sequence in array 
bool linearSearch_(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return true;
        }
    }
    return false;
}
void consecutiveSequence(int arr[],int n){
    int longest = 1;
    for(int i=0;i<n;i++){
        int x = arr[i];
        int cnt = 1;
        while(linearSearch_(arr,n,x+1) == true){
            x = x+1;
            cnt ++;
        }
  longest = max(longest,cnt);
    }
    cout<<"The longest consecutive sequence is: "<<longest;
}

// ------------longest consecutive sequence with optimisation
void consecutiveSequence_(int arr[],int n){
    sort(arr,arr+n);
    if(n == 0){
        return;
    }
    int cnt = 0;
    int last = INT_MIN;
    int longest = 1;
    for(int i=0;i<n;i++){
        if(arr[i]-1 == last){
            cnt++;
            last = arr[i];
        }
        else if(arr[i] != last){
            cnt = 1;
            last = arr[i];
        }
        longest = max(longest,cnt);
    }
    cout<<"The longest consecutive sequence is: "<<longest;
}

// -----------longest consecutive sequence with best optimisation 
void consecutiveSequence__(int arr[],int n){
    if(n == 0){
        return;
    }
    int longest = 1;
    unordered_set<int> temp;
    for(int i=0;i<n;i++){
        temp.insert(arr[i]);
    }
    for(auto i:temp){
        if(temp.find(i-1) == temp.end()){
            int cnt = 1;
            int x = i;
            while(temp.find(x+1) != temp.end()){
                x = x+1;
                cnt = cnt+1;
            }
            longest = max(longest,cnt);
        }
    }
    cout<<"The longest consecutive sequence is: "<<longest;
    
}

// -----------matrix of zeroes and ones
void markRow(int arr[][4],int i,int m){
    for(int j=0;j<m;j++){
        if(arr[i][j]!=0){
            arr[i][j] = -1;
        }
    }
}
void markColumn(int arr[][4], int j, int n){
    for(int i=0;i<n;i++){
        if(arr[i][j]!=0){
            arr[i][j] = -1;
        }
    }
}
void setMatrixZeroes(int arr[][4],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0){
                markRow(arr,i,m);
                markColumn(arr,j,n);                
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == -1){
                arr[i][j] = 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

// ---------------matrix of zeroes and ones with optimisation
void setMatrixZeroes_(int arr[][4],int n,int m){
    int row[m] = {0};
    int col[n] = {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i] == 1 || col[j] == 1){
                arr[i][j] = 0;
            }
        }
    } 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }   
}

// -------------rotate matrix by 90 degree
void rotateMatrix90(int arr[][3],int n){ 
    int matrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           matrix[j][n-i-1] = arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

// -------------rotate matrix by 90 degree with optimisation
void rotateMatrix90_(int arr[][3],int n){
    for(int i=0;i<n-1;i++){          // transpose
        for(int j=i+1;j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    for (int i = 0; i < n; i++) {   // reverse
        for (int j = 0; j < n / 2; j++) {
            swap(arr[i][j], arr[i][n - j - 1]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

// ----------spiral matrix
void spiralMatrix(int arr[][4],int n,int m){
    int top = 0, left = 0, bottom = n-1, right = m-1;

    while(top<=bottom && left<=right){

    for(int i=left;i<=right;i++){
        cout<<arr[top][i]<<" ";
    }
    top++;
    for(int i=top;i<=bottom;i++){
        cout<<arr[i][right]<<" ";
    }
    right--;
    if(top<=bottom){
    for(int i=right;i>=left;i--){
        cout<<arr[bottom][i]<<" ";
    }
    bottom--;
    }
    if(left<=right){
    for(int i=bottom;i>=top;i--){
        cout<<arr[i][left]<<" ";
    }
    left++;
  }
 }

}

// -----------counting the no. of subaaray with sum k
void subarraySum(int arr[],int n,int k){
    int cnt = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
               if(sum == k){
                cnt++;
            }
        }
    }
    cout<<"The no. of subarray are: "<<cnt;
}

// ---------------counting the no. of subaaray with sum k with optimissation
void subarraySum_(int arr[],int n,int k){
    int cnt = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
           
            // not understanding 😭😭😭
            
        }
    }
    cout<<"The no of subarray with sum "<<k<<" is "<<cnt;
}

// ----------pascal's triangle - getting the element at given position
int nCr(int n,int r){
   int res = 1;
   for(int i=0;i<r;i++){
    res = res * (n-i);
    res = res/(i+1);
   }
   return res;
}

// ----------pascal's triangle - printing the complete row
void pascal(int row){
    int ans = 1;
    cout<<ans<<" ";
    for(int i=1;i<row;i++){
        ans = ans*(row-i);
        ans = ans/i;
        cout<<ans<<" ";
    }
}

// ----------pascal's triangle - printing the entire triangle
void pascalTriangle(int n){
    for(int i=0;i<n;i++){
        int ans = 1;
        for(int j=0;j<=i;j++){
            cout<<ans<<" ";
            ans = ans*(i-j)/(j+1);
            }
            cout<<endl;
        }
}

// ----------majority element > n/3 times
void majorityby3(int arr[],int n){
    unordered_set<int> temp;  
    
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                cnt++;
            }
        }
        if (cnt > n / 3) {
            temp.insert(arr[i]); 
        }
    }
  cout<<"Majority element: ";
  for(int i:temp){
    cout<<i<<" ";
  }
}

// ----------majority element > n/3 times using optimisation
void majorityby3_(int arr[],int n){
    list<int> li;
    int mini = (n/3) + 1;
    unordered_map<int,int> temp;
    for(int i=0;i<n;i++){
        temp[arr[i]]++;
        if(temp[arr[i]] == mini){
            li.push_back(arr[i]);
        }
    }
    cout << "Majority element(s) > n/3 times: ";
    for (int num : li) {
        cout << num << " ";
    }
    cout << endl;
}

// ---------majority element > n/3 times using best optimisation using moore's voting algorithm
void majorityby3__(int arr[],int n){
    int cnt1 = 0, cnt2 = 0;
    int el1, el2;
    for(int i=0;i<n;i++){
        if(cnt1 == 0 && arr[i]!=el2){
         cnt1 = 1;
         el1 = arr[i];
        }
        else if(cnt2 == 0 && arr[i]!= el1){
            cnt2 = 1;
            el2 = arr[i];
        }
        else if(el1 == arr[i]){
            cnt1++;
        }
        else if(el2 == arr[i]){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    int cnt3 = 0,cnt4 = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == el1){
            cnt3++;
        }
        if(arr[i] == el2){
            cnt4++;
        }
    }
    int mini = (n/3) + 1;
    if(cnt3>=mini){
        cout<<"Majority element is:"<<el1;
    }
    if(cnt4>=mini){
        cout<<"Majority element is:"<<el2; 
    }
}

// ----------3 Sum - sum of three element in array is 0
void threeSum(int arr[],int n){
    set<vector<int>> s;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
             if(arr[i] + arr[j] + arr[k] == 0){
                vector<int> temp = {arr[i], arr[j], arr[k]};
                sort(temp.begin(),temp.end());
                s.insert(temp);
             }   
            }
        }
    }
    for (auto triplet : s) {
        cout << "[";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }
}

// ---------3 sum - finding three element whose sum is 0 using optimissation
void threeSum_(int arr[],int n){
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        set<int> hash;
        for(int j=i+1;j<n;j++){
            int third = -(arr[i]+arr[j]);
            if(hash.find(third) != hash.end()){
                vector<int> temp = {arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hash.insert(arr[j]);
        }
    }
    for (auto triplet : st) {
        cout << "[";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    } 
}

// ---------3 sum - finding three element whose sum is 0 using best optimissation
void threeSum__(int arr[],int n){
    sort(arr,arr+n);
   
    for(int i=0;i<n;i++){    
        if (i > 0 && arr[i] == arr[i - 1])  // Skip duplicate elements
        continue;
        int j = i+1;
        int k = n-1;  
        while(j<k){
        if(arr[i]+arr[j]+arr[k] < 0){
            j++;
        }
        else if(arr[i]+arr[j]+arr[k] > 0){
            k--;
        }
        else{
            cout<<arr[i]<<","<<arr[j]<<","<<arr[k];
            j++;
            k--;
            while(j<k && arr[j] == arr[j-1]){
                j++;
            }
            while(j<k && arr[k] == arr[k-1]){
                k--;
            }
        }
      }
    }
    
}

// ---------4 sum
void fourSum(int arr[],int n){
    set<vector<int>> uniqueQuadruplets;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    int sum = arr[i] + arr[j] + arr[k] + arr[l];
                    if(sum == 0){
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());  // Sort to avoid duplicate sets
                        uniqueQuadruplets.insert(temp);
                    }
                }
            }
        }
    }
    for (auto quad : uniqueQuadruplets) {
        cout << "[ ";
        for (int num : quad) {
            cout << num << " ";
        }
        cout << "]\n";
    }
}

// ---------4 sum with best optimisatiion 
void fourSum_(int arr[],int n){
    sort(arr,arr+n);
     int target = 8;
    for (int i = 0; i < n - 3; i++) {  
        if (i > 0 && arr[i] == arr[i - 1]) continue; // Skip duplicate values
        
        for (int j = i + 1; j < n - 2; j++) {  
            if (j > i + 1 && arr[j] == arr[j - 1]) continue; // Skip duplicate values
            
            int left = j + 1, right = n - 1; // Two-pointer approach for the last two numbers
            
            while (left < right) {
                int sum = arr[i] + arr[j] + arr[left] + arr[right];
                
                if (sum == target) {
                    cout << arr[i] << " " << arr[j] << " " << arr[left] << " " << arr[right] << endl;
                    left++;
                    right--;

                    // Skip duplicates
                    while (left < right && arr[left] == arr[left - 1]) left++;
                    while (left < right && arr[right] == arr[right + 1]) right--;
                } 
                else if (sum < target) left++;   // Increase sum
                else right--;  // Decrease sum
            }
        }
    }
}

// ---------number of subarray with XOR as k
void subarrayXOR(int arr[],int n,int k){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int XOR = 0;
            for(int l=i;l<j;l++){
                XOR = XOR^arr[l];
                if(XOR == k){
                    cnt++;
                }
            }
        }
    }
    cout<<"The number of subarray with XOR k is: "<<cnt;
}

// ---------number of subarray with XOR as k with optimisation
void subarrayXOR_(int arr[],int n,int k){
    int cnt = 0;
    for(int i=0;i<n;i++){
        int XOR = 0;
        for(int j=i;j<n;j++){
                XOR = XOR^arr[j];
                if(XOR == k){
                    cnt++;
                }
            }
        }
        cout<<"The number of subarray with XOR k is: "<<cnt;
}

// -----------number of subarray with XOR as k with best optimisation
void subarrayXOR__(int arr[],int n){
   
    

    // unable to understand this 😞😭😔 - lecture number 38 
}

// ------------merging the overlapping subintervals
vector<vector<int>> mergeSubIntervals(vector<vector<int>> arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0;i<arr.size();i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<arr.size();j++){
            if(arr[j][0] <= end){
                end = max(end,arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}

// -----------merging the overlapping subintervals with optimisation
vector<vector<int>> mergeSubIntervals_(vector<vector<int>> arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0;i<arr.size();i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}

// ---------merge two sorted array in the original array 
void mergeSortedArray(int arr[],int n, int arr1[],int m){
    int* arr2 = new int[n + m];
     int i = 0,j = 0;
     int cnt = 0;
     while(i<n && j<m){
        if(arr[i] > arr1[j]){
            arr2[cnt] = arr1[j];
            j++;
            cnt++;
        }
        else if(arr[i] < arr1[j]){
            arr2[cnt] = arr[i];
            i++;
            cnt++;
        }
        else{
            arr2[cnt++] = arr[i];
            arr2[cnt++] = arr1[j];
            i++;
            j++;
        }
     }
     while(j<m){
        arr2[cnt++] = arr1[j++];
     }
     while(i<n){
        arr2[cnt++] = arr[i++];
     }
    // put the element in the original array 
    for(int i=0;i<n;i++){
        arr[i] = arr2[i];
    }
    for(int j=0;j<m;j++){
        arr1[j] = arr2[j + n];
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int j=0;j<m;j++){
        cout<<arr1[j]<<" ";
    }
}

// -------------merge two sorted array without using any extra space with optimisation
void mergeSortedArray_(int arr[],int n,int arr1[],int m){
    int i = n-1;
    int j = 0;
    while(i>=0 && j<m){
        if(arr[i] > arr1[j]){
            swap(arr[i], arr1[j]);
            i--;
            j++;
        }
        else{
            break;
        }
    }
    sort(arr,arr+n);
    sort(arr1,arr1+m);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int j=0;j<m;j++){
        cout<<arr1[j]<<" ";
    }
}

// -------------merge two sorted array into original array without using extra space with optimisation - using shell sort (gao method)
void mergeSortedArray__(int arr[],int n,int arr1[],int m){
    int len = n+m;
    int gap = (len/2) + (len%2);   // ceil operation
    while(gap>0){
    int left = 0;
    int right = gap + left;
    while(right<len){
        if(left<n && right >=n){
            if(arr[left] > arr1[right - n]){
                swap(arr[left],arr1[right-n]);
         
            }
         }
         else if(left >= n){
            if(arr[left-n] > arr1[right - n]){
                swap(arr[left-n],arr1[right-n]);    
            }
         }
        else{
            if(arr[left] > arr[right]){
                swap(arr[left],arr[right]);
            }        
        }
        left++;
        right++;
      }
      if(gap == 1){
        break;
      }
      gap = (gap/2) + (gap%2);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int j=0;j<m;j++){
        cout<<arr1[j]<<" ";
    }
}

// -----------find the missing number and repeating number
void repeatingMissing(int arr[],int n){
    for(int i=1;i<n;i++){
        int cnt = 0;  
        for(int j=0;j<n;j++){
            if(arr[j] == i){
                cnt++;
            }
        }
        if(cnt == 2){
            cout<<"The repeating number is: "<<i<<endl;
        }
        else if(cnt == 0){
            cout<<"The missing number is: "<<i;
        }
    }
}

// -----------find the missing number and repeating number with optimisaiton 
void repeatingMissing_(int arr[],int n){
    int hash[n+1] = {0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(hash[i] == 0){
            cout<<"The missing number is: "<<i<<endl;
        }
        if(hash[i] == 2){
            cout<<"The repeating number is: "<<i;
        }
    }
}

// ----------find the missing number and repeating number with best optimisaiton  - using matrix method 
void repeatingMissing__(int arr[],int n){
    int sum = (n*(n+1))/2;
    long long sumSquare = (n*(n+1) * (2*n+1)/6);
    long long s = 0, s2 = 0;
    for(int i=0;i<n;i++){
        s += arr[i];
        s2 += arr[i]*arr[i];
    }
    int val1 = s - sum;
    int val2 = s2 - sumSquare;
    // X-Y = val1
    // X^2 - Y^2 = val2 - (X-Y)+(X+Y)
    val2 = val2/val1;
    long long x = (val1 + val2)/2;
    long long y = x - val1;
    cout<<"The missing number is: "<<y<<endl;
    cout<<"The repeating number is: "<<x;   
}
  
// -------------find the missing number and repeating number with best optimisaiton - using XOR method
void repeatingMissing___(int arr[],int n){
    // very tough 🥶

    // very large 🥵😵‍💫
}

// -----------count inversion - pairs with left element greater than right
void countInversion(int arr[],int n){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                cnt++;
            }
        }
    }
    cout<<"The number of pairs are: "<<cnt;
}

// -----------count inversion - pairs with left element greater than right with optimisation
int cnt = 0;
void merge(int arr[],int low,int mid,int high){
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
    int p=0,q=0;
    int k=low;
    while(p<an && q<bn){
        if(a[p]<=b[q]){
            arr[k] = a[p];
            p++;
        }
        else{
            arr[k] = b[q];
            cnt += (an - p);
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
void mergeSort(int arr[],int low,int high){
    if(low>=high){
        return;
    }
    int mid = (low + high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int countInversion_(int arr[],int n){
    mergeSort(arr,0,n-1);
    cout<<"The number of pairs are: "<<cnt;
}

// -------------reverse pair - pairs with left element greater than twice the right element
void reversePair(int arr[],int n){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>2*arr[j]){
                cnt++;
            }
        }
    }
    cout<<"The number of pairs are: "<<cnt;
}

// -------------reverse pair - pairs with left element greater than twice the right element with optimisation
int cnt1 = 0;
void merge_(int arr[],int low,int mid,int high){
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
void countPairs(int arr[],int low,int mid,int high){
    int right = mid+1;
    for(int i=low;i<=mid;i++){
        while(right<=high && arr[i] > 2*arr[right]){
            right++;
        }
        cnt1 = cnt1 + (right - (mid +1));
    }
}
void mergeSort_(int arr[],int low,int high){
    if(low>=high){
        return;
    }
    int mid = (low + high)/2;
    mergeSort_(arr,low,mid);
    mergeSort_(arr,mid+1,high);
    countPairs(arr,low,mid,high);
    merge_(arr,low,mid,high);
}
void reversePair_(int arr[],int n){
    cnt1 = 0;
    mergeSort_(arr,0,n-1);
    cout<<"The number of pairs are: "<<cnt1;
}

// --------------maximum product in subarray
void maximumProductSubarray(int arr[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int product = 1;
            for(int k = i;k<j;k++){
            product = product * arr[k];
        }
        maxi = max(product,maxi);
        }
    }
    cout<<"The maximum product is: "<<maxi;
}

// ----------maximum product in subarray with optimisation
void maximumProductSubarray_(int arr[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int product = 1;
        for(int j=i;j<n;j++){
            product = product*arr[j];
            maxi = max(product,maxi);
        }
    }
    cout<<"The maximum product is: "<<maxi;
}

// ----------maximum product in subarray with best optimisation
void maximumProductSubarray__(int arr[],int n){
    // if there are all positive numbers then multiply all 
    //if there are even no. of negative numbers then also multiply all - because even negative make a positive
    // if there are zero then reset to 1
    int prefix = 1;
    int suffix = 1;
    int ans = INT_MIN;
     for(int i=0;i<n;i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;
        prefix = prefix * arr[i];
        suffix = suffix * arr[n-i-1];
        ans = max(ans,max(prefix,suffix));
     }
     cout<<"The maximum product is: "<<ans;
}

int main() {
    //  ---------- 1D  array 

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // int n1;
    // cout<<"Enter the size of array: ";
    // cin>>n1;
    // int arr1[n1];
    // cout<<"Enter the elements of the array: ";
    // for(int i=0;i<n1;i++){
    //     cin>>arr1[i];
    // }


    // -------remove duplicates
    // removeDuplicate(arr,n);


    // -------remove duplicates with optimisation
    // removeDuplicate_(arr,n);


    // -------largest element in array
    // cout<<"The largest element in the array is: "<<largest(arr,n)<<endl;

    
    // --------second largest element in array
    // cout<<"The second largest element is: "<<second_largest(arr,n)<<endl;


    // --------second largest element in array with optimisation
    // cout<<"The second largest element is: "<<second_largest_(arr,n)<<endl;


    // --------second largest element in array with best optimisation with time complexity
    // cout<<"The second largest element is: "<<second_largest__(arr,n)<<endl;


    // --------left rotate the array by one
    // leftRotate(arr,n);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;


    // --------left rotate the array by certain
    // int p;
    // cout<<"Enter how many position you want to shift: ";
    // cin>>p; 
    // leftRotateByN(arr,n,p);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }


    // -----left rotate by certain using optimisation
    // leftRotateByN_(arr,n,3);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    //     }


    // ----------moving zeroes at the end of the array
    // movingZeroes(arr,n);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }


    // ----------moving zeroes at the end of the array with optimisation
    // movingZeroes_(arr,n);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }


    // ---------linear search
    // int key;
    // cout<<"Enter the value you want to find: ";
    // cin>>key;
    // cout<<"The index at which the key is found is: "<<linearSearch(arr,n,key);;


    // -----------union two of array
    // unionArray(arr,arr1,n,n1);

    
    // -----------union two of array with optimisation
    // unionArray_(arr,arr1,n,n1);


    // ----------intersection of two array
    // intersection(arr,arr1,n,n1);
    

    // ----------intersection of two array with optimisation
    // intersection_(arr,arr1,n,n1);

    
    // ----------intersection of two array with best optimisation
    // intersection__(arr,arr1,n,n1);


    // ---------finding missing number from array
    // missing(arr,n);

    
    // ---------finding missing number from array with optimisation
    // missing_(arr,n);

        
    // ---------finding missing number from array with best optimisation
    // --------one point to be noted that the number you want to miss replace it with 0 
    // missing__(arr,n);
        
    // ---------finding missing number from array with bestest optimisation
    // missing___(arr,n);


    // ----------maximum consecutive one in a array
    // consecutive(arr,n);


    // -----------the number which appears only a single times, all other comes twice
    // singleNumber(arr,n);

    
    // -----------the number which appears only a single times, all other comes twice with optimisation
    // singleNumber_(arr,n);

    
    // -----------the number which appears only a single times, all other comes twice with best optimisation
    // singleNumber__(arr,n);


    // -----------the number which appears only a single times, all other comes twice with bestest optimisation
    // singleNumber___(arr,n);

    // ------------two sum
    // int target;
    // cout<<"Enter the target: ";
    // cin>>target;
    // twoSum(arr,n,target);

    // ------------two sum with optimisation
    // int target;
    // cout<<"Enter the target: ";
    // cin>>target;
    // twoSum_(arr,n,target);


    // ----------two sum with better optimisation
    // int target;
    // cout<<"Enter the target: ";
    // cin>>target;
    // twoSum__(arr,n,target);


    // ----------sort 0's 1's 2's
    // sort0s1s2s(arr,n);

    
    // ----------sort 0's 1's 2's wiht optimisation
    // sort0s1s2s_(arr,n);

    
    // ----------sort 0's 1's 2's with best optimisation
    // sort0s1s2s__(arr,n);


    // ----------majority element in an array
    // cout<<"The majority element is: "<<majority(arr,n);

    
    // ----------majority element in an array with optimisation
    // cout<<"The majority element is: "<<majority_(arr,n);

    
    // ----------majority element in an array with best optimisation using moore's alogorithm
    // cout<<"The majority element is: "<<majority__(arr,n);


    // ---------maximum subarray sum 
    // maxSubarray(arr,n);


    // -----------maximum subarray sum with optimisation
    // maxSubarray_(arr,n);


    // -----------maximum subarray sum with optimisation using kadane's algorithm
    // maxSubarray__(arr,n);


    // --------buy and sell using array
    // buySellStock(arr,n);


    // --------rearrange array element by sign
    // rearrangeBySign(arr,n);
    

    // --------rearrange array element by sign with optimisation
    // rearrangeBySign_(arr,n);


    // ----------next permutation with built-in function
    // permutation(arr,n);


    // ----------next permutation with optimisation
    // permutation_(arr,n);


    // ----------leaders in array
    // leaders(arr,n);

    
    // ----------leaders in array with optimisation
    // leaders_(arr,n);


    // ------------longest consecutive sequence
    // consecutiveSequence(arr,n);


    // ------------longest consecutive sequence with optimisation
    // consecutiveSequence_(arr,n);


    // ------------longest consecutive sequence with  best optimisation
    // consecutiveSequence__(arr,n);


    // ------------2D array
    // int n,m;
    // cout<<"Enter the size: ";
    // cin>>n>>m;
    // int arr1[n][4];
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cin>>arr1[i][j];
    //     }
    // }


    // --------------set matrix zeroes
    // setMatrixZeroes(arr1,n,m);


    // --------------set matrix zeroes with optimisation
    // setMatrixZeroes_(arr1,n,m);


    // ------------rotate matrix by 90degree
    // rotateMatrix90(arr1,n);


    // ------------rotate matrix by 90degree with optimisation
    // rotateMatrix90_(arr1,n);


    // ------------spiral matrix
    // spiralMatrix(arr1,n,m);


    // ------------counting the no. of subaaray with sum k
    // int k;
    // cout<<"Enter the value of k: ";
    // cin>>k;
    // subarraySum(arr,n,k);


    // ------------counting the no. of subaaray with sum k
    // subarraySum_(arr,n,k);


    // ------------pascal's triangle - getting the element at given position
    // cout<<"The element is:"<<nCr(4,2);


    // ----------pascal's triangle - printing the complete row
    // int row;
    // cin>>row;
    // pascal(row);


    // -----------pascal's triangle - printing the complete triangle
    // int no;
    // cin>>no;
    // pascalTriangle(no);

    
    // ----------majority element > n/3 times
    // majorityby3(arr,n);

    
    // ----------majority element > n/3 times using optimisation
    // majorityby3_(arr,n);

    
    // ----------majority element > n/3 times using best optimisation using moore's a;goruthm
    // majorityby3__(arr,n);


    // ---------three sum
    // threeSum(arr,n);

    
    // ---------three sum with optimisation
    // threeSum_(arr,n);

    
    // ---------three sum with  best optimisation
    // threeSum__(arr,n);


    // ----------four sum 
    // fourSum(arr,n);


    // ----------four sum with best optimisation 
    // fourSum_(arr,n);


    // ----------number of subarray with xor k
    // int k;
    // cout<<"Enter the value of k: ";
    // cin>>k;
    // subarrayXOR(arr,n,k);


    // ----------number of subarray with xor k with optimisation
    // int k;
    // cout<<"Enter the value of k: ";
    // cin>>k;
    // subarrayXOR_(arr,n,k);


    // ---------number of subarray with xor k with best optimisation



    // --------merging the overlapping subintervals
    // int n;
    // cout<<"Enter the number of intervals: ";
    // cin>>n;
    // vector<vector<int>> arr(n,vector<int>(2));
    // cout << "Enter the intervals (start and end):\n";
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i][0] >> arr[i][1]; 
    // }
    // vector<vector<int>> result = mergeSubIntervals(arr);
    // cout << "Merged Intervals:\n";
    // for (auto &interval : result) {
    //     cout << "[" << interval[0] << ", " << interval[1] << "] ";
    // }


    // --------merging the overlapping subintervals with optimisation
    // int n;
    // cout<<"Enter the number of intervals: ";
    // cin>>n;
    // vector<vector<int>> arr(n,vector<int>(2));
    // cout << "Enter the intervals (start and end):\n";
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i][0] >> arr[i][1]; 
    // }
    // vector<vector<int>> result = mergeSubIntervals_(arr);
    // cout << "Merged Intervals:\n";
    // for (auto &interval : result) {
    //     cout << "[" << interval[0] << ", " << interval[1] << "] ";
    // }


    // -----------merge two sorted array into the original array 
    // mergeSortedArray(arr,n,arr1,n1);

    
    // -----------merge two sorted array without using extra space using optimisation
    // mergeSortedArray_(arr,n,arr1,n1);

    
    // -----------two sorted array without using extra space using optimisation
    // mergeSortedArray__(arr,n,arr1,n1);

    
    // -----------find the missing number and repeating number
    // repeatingMissing(arr,n);

    
    // -----------find the missing number and repeating number with optimisation
    // repeatingMissing_(arr,n); 

    
    // -----------find the missing number and repeating number with best optimisation - matrix method
    // repeatingMissing__(arr,n);
    

    // -----------find the missing number and repeating number with best optimisation - xor method
    // repeatingMissing___(arr,n);


    // -----------count inversion - pair having left grater than right
    // countInversion(arr,n);


    // -----------count inversion - pair having left grater than right with optimisation
    // countInversion_(arr,n);


    // -------------reverse pair - pairs with left element greater than twice the right element
    // reversePair(arr,n);


    // -------------reverse pair - pairs with left element greater than twice the right element with optimisation
    // reversePair_(arr,n);

    
    // --------------maximum product in subarray
    // maximumProductSubarray(arr,n);
    

    // --------------maximum product in subarray with optimisation
    // maximumProductSubarray_(arr,n);


    // --------------maximum product in subarray with best optimisation
    // maximumProductSubarray__(arr,n);

    return 0;
}