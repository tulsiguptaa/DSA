#include <bits/stdc++.h>
using namespace std;


// -----------<BINARY SEARCH PROBLEMS>--------------------//


// ------------lower bound - smallest index with arr[i] >= x , however the array is already sorted
void lowerBound(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]>=x){
            cout<<"The index is: "<<i;
            return;
        }
    }
}

// -----------lower bound - smallest index with arr[i] >= x with optimisation
int lowerBound_(int arr[],int n,int x){
    sort(arr,arr+n);  // we actually dont need this because the array is already taken sorted but for the sake of error handling 
    int low = 0;
    int high = n-1;
    int ans = n;   // if not found then it will be the next hypothetical index
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] >= x){
            high = mid-1;
            ans = mid;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

// ---------------upper bound - smallest index with arr[i] > x
void upperBound(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]>x){
            cout<<"The upper bound is: "<<i;
            return;
        }
    }
}

// ---------------upper bound - smallest index with arr[i] > x with optimisation
int upperBound_(int arr[],int n,int x){
    int low = 0;
    int high = n;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

// ----------------Search insert position - insert the element in an array at correct position and get the index - same as lower bound
void insertPosition(int arr[],int n,int x){
    int ans = n;
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>=x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<"The insertion position is: "<<ans;
}

// ---------------floor in sorted array - floor - largest no.<=x 
void floor(int arr[],int n,int x){
    int low = 0;
    int high = n-1;
    int idx = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]<=x){
            idx = mid;
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    } 
    cout<<"The floor is at index "<<idx<<" and the value is: "<<arr[idx];
}

// --------------ceil in sorted array - ceil - smallest no. >=x
void ceil(int arr[],int n, int x){
    int low = 0;
    int high = n-1;
    int idx = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>=x){
            idx = mid;
            high = mid -1;            
        }
        else{
            low = mid + 1;
        }
    } 
    cout<<"The ceil is at index "<<idx<<" and the value is: "<<arr[idx];
}

// -------------first and last occurence of x
void occurence(int arr[],int n,int x){
    int low = n;
    int high = -1;
    for(int i=0;i<n;i++){
        if(arr[i] == x){
            low = min(low,i);
            high = max(i,high);
        }
    }
    cout<<"The indexes are: {"<<low<<", "<<high<<"}";
}

// -------------first and last occurence of x with optimisation
void occurence_(int arr[],int n,int x){
    int lb = lowerBound_(arr,n,x);   // as the lower bound finds the first occurence of element
    int ub = upperBound_(arr,n,x);   // as upper bound finds the index greater than a number so by subtracting 1 , we get the index
    if(arr[lb] == x){       // this check is the number is same as the x 
    cout<<"The indexes are: {"<<lb<<", "<<(ub-1)<<"}";
    }
    else{
        cout<<"The element is not found in the array";
    }
}

// ------------first occurence without using lower bound 
void firstOccurence(int arr[],int n,int x){
    int low = 0;
    int high = n-1;
    int idx = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == x){
            idx = min(mid,idx);
            high = mid - 1; 
        }
        else if(arr[mid]>x){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    if(arr[idx] == x){
    cout<<"The first occurence is: "<<idx;
    }
    else{
        cout<<"The element is not found in the array";
    }
}

// -----------last occurence without using upper bound
void lastOccurence(int arr[],int n,int x){
    int low = 0;
    int high = n-1;
    int idx = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == x){
            idx = max(idx,mid);
            low = mid + 1;
        }
        else if(arr[mid]<x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    if(arr[idx] == x){
        cout<<"The last occurence is: "<<idx;
    }
    else{
        cout<<"The element is not found in the array";
    }
}

// -----------search in rotated sorted array with no duplicates
void rotatedSearch(int arr[],int n,int x){
    int low = 0;
    int high = n-1;
    int idx;
    while(low<=high){
        int mid = (low+high)/2;
        bool unsorted_half = false;
        if(arr[mid] == x){
           cout<<"The target is found at position "<<mid;
           return;
        }
        // find the sorted half  
        // left sorted
        if(arr[mid]>=arr[low]){
            if(arr[low]<=x && x<=arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        // right sorted
        else{
            if(arr[mid]<=x && x<=arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    cout<<"The target is not present";
}

// ------------search in rotated sorted array with duplicates element present - unable to identify the sorted array - [3,2,1,3,3,3,3] - here the last is same as middle so right is sorted and the first is same as middle so left is sorted
bool rotatedSearchDuplicates(int arr[],int n,int x){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == x){
            return true;
        }
        if(arr[mid] == arr[low] && arr[mid] == arr[high]){
            low++;
            high--;
            continue;
        }
        else if(arr[mid]>=arr[low]){
            if(arr[low]<=x && x<=arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(arr[high]>=x && x>=arr[mid]){
               low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    
}

// -------------minimum in rotated sorted array
int minimumInRotated(int arr[],int n){
    int low = 0;
    int high = n-1;
    int mini = INT_MAX;
    while(low<=high){
        int mid = (low+high)/2;
        // if any half is already sorted no need to do half and half just return the low
        if(arr[low]<=arr[high]){
            return min(mini,arr[low]);
        }
        if(arr[mid]>=arr[low]){
            low = mid + 1;
            mini = min(mini,arr[low]);   // [4,5,6,1,2,3]  // here the middle element is min but as it is included in sorted right half, it will eliminate so always store the minimum of the sorted half
        }
        else{
            high = mid - 1;
            mini = min(mini,arr[mid]);
        }
    }
    return mini;
}

// -------------minimum in rotated sorted array with duplicates
int minimumInRotatedDuplicates(int arr[],int n){
    int low = 0;
    int high = n-1;
    int mini = INT_MAX;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == arr[high] && arr[mid] == arr[low]){
            low++;
            high--;
            continue;
        }
        else if(arr[mid]>=arr[low]){
            low = mid + 1;
            mini = min(mini,arr[low]);   // [4,5,6,1,2,3]  // here the middle element is min but as it is included in sorted right half, it will eliminate so always store the minimum of the sorted half
        }
        else{
            high = mid - 1;
            mini = min(mini,arr[mid]);
        }
    }
    return mini;
}

// -------------number of times array rotated
int rotatedNumber(int arr[],int n){
    int low = 0;
    int high = n-1;
    int idx = -1;
    int mini = INT_MAX;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[low]<=arr[high]){
            if(arr[low]<mini){
                idx = low;
                mini = arr[low];
            }
            break;
        }
        // right sorted
        if(arr[mid]<=arr[low]){
            if(arr[mid]<mini){
                idx = mid;
                mini = arr[mid];
            }
            high = mid - 1;
        }
        else{
            if(arr[low]<mini){
                idx = low;
                mini = arr[low];
            }
            low = mid + 1;
        }
    }
    return idx;
}

// --------------number of times array is rotated contains duplictes
int rotatedNumberDuplicates(int arr[],int n){
        int low = 0;
        int high = n-1;
        int idx = -1;
        int mini = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            // if already sorted
            if(arr[low]<arr[high]){
                if(arr[low]<mini){
                    idx = low;
                    mini = arr[low];
                }
                break;
            }
            else if(arr[low] == arr[mid] && arr[mid] == arr[high]){
                if(arr[mid]<mini){
                    idx = mid;
                    mini = arr[mid];
                }
                low++;
                high--;
                continue;
            }
            // right sorted
            else if(arr[mid]<=arr[low]){
                if(arr[mid]<mini){
                    idx = mid;
                    mini = arr[mid];
                }
                high = mid - 1;
            }
            else{
                if(arr[low]<mini){
                    idx = low;
                    mini = arr[low];
                }
                low = mid + 1;
            }
        }
        return idx;
    
}

// -----------single element in a sorted array
int singleElement(int arr[],int n){
    for(int i=0;i<n;i++){
        if(n==1){
            return arr[0];
        }
        if(i==0){
            if(arr[i] != arr[i+1]){
                return arr[i];
            }
        }
        else if(i == n-1){
            if(arr[i]!= arr[i-1]){
                return arr[i];
            }
        }
        else{
            if(arr[i]!= arr[i+1] && arr[i]!=arr[i-1]){
                return arr[i];
            }
        }
    }
}

// ------------single element in a sorted array using optimisation
int singleElement_(int arr[],int n){
    if(n==1){
        return arr[0];
    }
    if(arr[0] != arr[1]){
        return arr[0];
    }
    if(arr[n-1] != arr[n-2]){
        return arr[n-1];
    }
    int low = 1;
    int high = n-2;
    // (even,odd) idx - left eliminate
    // (odd,even) idx - right eliminate
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!= arr[mid+1]){    // the middle element is single
            return arr[mid];
        }
        if((arr[mid]==arr[mid-1] && mid%2==1) || (mid%2==0 && arr[mid] == arr[mid+1])){    // (even,odd)
            low = mid + 1;
        }
        else{    // (odd,even)
            high = mid - 1; 
        }
    }
    return -1;
}

// -------------peak element - arr[i-1] < arr[i] > arr[i+1]
int peakElement(int arr[],int n){
    if(n==1) return arr[0];
    if (arr[0] > arr[1]) return arr[0];
    if (arr[n - 1] > arr[n - 2]) return arr[n - 1];
    for(int i=1;i<n-1;i++){
        if(arr[i]>arr[i-1] && arr[i] > arr[i+1]){
            return arr[i];
        }
    }
}

// -----------peak element with optimisation
int peakElement_(int arr[],int n){
    if(n==1) return arr[0];
    if(arr[0]>arr[1]){
        return arr[0];
    }
    if(arr[n-1]>arr[n-2]){
        return arr[n-1];
    }
    int low = 1;
    int high = n-2;
    int idx = 0;
    int arr1[idx];
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
            return arr[mid];
        }
        else if(arr[mid]>arr[mid+1]){
            high = mid - 1;
        }
        else if(arr[mid]>arr[mid-1]){
            low = mid + 1;
        }
        else{          // we are writing this extra else because if the mid element is smaller than both the mid-1 and mid+1 in the case of multiple peak
            low = mid + 1;
        }
    }  
    return -1;
}

// --------------sqrt of an integer
int sqrt(int n){
    int ans = 1;
    for(int i=1;i<=n;i++){
        if(i*i <= n){
            ans = i;
        }
        else{
            break;
        }
    }
    return ans;
}

// ---------sqrt of an integer using optimisation
int sqrt_(int n){
    int low = 1;
    int high = n;
    int ans = 1;
    while(low<=high){
        int mid = (low+high)/2;
        if(mid*mid == n){
            return mid;
        }
        if((mid*mid)>n){
            high = mid - 1;  
        }
        else if((mid*mid)<n){
            ans = max(ans,mid);
            low = mid + 1;
        }
    }
    return ans;
}

// ------------find nth root of m
int root(int n,int m){
    for(int i=1;i<=n;i++){
        int power = 1;
        for(int j=0;j<m;j++){
            power *= i;
            if(power>n) break;
        }
       if(power == n){
        return i;
       }
       else if(power>n){
        break;
       }
    }
    return -1; 
}

// -----------find the nth root with optimisaiton - slightly difficult
int power(int mid,int m,int n){
    int ans = 1;
    for(int i=1;i<=m;i++){
        ans = ans*mid;
        if(ans>n) return 2;
    }
    if(ans == n) return 1;
    return 0;
}
int root_(int n,int m){
    int low = 1;
    int high = n;
    while(low<=high){
        int mid = (low+high)/2;
        int midPower = power(mid,m,n);
        if(midPower==1) return mid;
        else if(midPower == 2){
            high = mid - 1;
        }    
        else{
            low = mid + 1;
        }
    }
    return -1;
}

// ---------koko eating bananas - minimum bananas/hr to eat all bananas with h hrs
int maximum(int arr[],int n){
    sort(arr,arr+n);
    return arr[n-1];
}
int total(int arr[],int n,int k){
    int totalHrs = 0;
    for(int i=0;i<n;i++){
        totalHrs += ceil((float)arr[i] / k);
    }
    return totalHrs;
}
int koko(int arr[],int n,int h){
    int requiredTime = 0;
    for(int i=1;i<=maximum(arr,n);i++){
        requiredTime = total(arr,n,i);
        if(requiredTime <= h){
            return i;
        }
    }
    return -1;
}

// ---------koko eating bananas - minimum bananas/hr to eat all bananas with h hrs with optimisation
int koko_(int piles[],int n,int h){
    int maxi = maximum(piles,n);
    int low = 1;
    int high = maxi;
    int ans = INT_MIN;
    while(low<=high){
        int mid = (low + high)/2;
        if(total(piles,n,mid) <= h){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

// ------------minimum number of days to make M bouquets with bloomed flowers
bool possible(int bloomday[],int n,int day,int m,int k){
    int no_of_bouq = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(bloomday[i]<=day){
            cnt++;
        }
        else{
            no_of_bouq += cnt/k;
            cnt = 0;
        }
    }
    no_of_bouq += cnt/k;
    if(no_of_bouq>=m) return true;
    else return false; 
}
int bouquets(int bloomday[],int n,int m,int k){
    if(m*k>n) return -1;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, bloomday[i]);
        maxi = max(maxi, bloomday[i]);
    }
    for(int i=mini;i<=maxi;i++){
        if(possible(bloomday,n,i,m,k) == true){
            return i;
        }
    }
    return -1;
}

// ------------minimum number of days to make M bouquets with bloomed flowers - k is no. of consecuent days with bianry search
int bouquets_(int bloomday[],int n,int m,int k){
    if(m*k>n) return -1;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, bloomday[i]);
        maxi = max(maxi, bloomday[i]);
    }
    int low = mini;
    int high = maxi;
    int ans = high;
    while(low<=high){
        int mid =(low+high)/2;
        if(possible(bloomday,n,mid,m,k) == false){
            low = mid + 1;
        }
        else{
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

// --------------find the smallest divisor given a threshold 
int divisor(int arr[],int n,int d,int t){
    int res = 0;
    for(int i=0;i<n;i++){
        res += ceil((float)arr[i]/d);
    }
    return res;
}
int threshold(int arr[],int n,int t){
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }
    for(int i=1;i<=maxi;i++){
        int divi = divisor(arr,n,i,t);
        if(divi <= t){
            return i;
        }
    }
    return -1;
}

// ---------------find the smallest divisor given a threshold with B.S.
int threshold_(int arr[],int n,int t){
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }
    int low = 1;
    int high = maxi;
    int res = -1;
    while(low<=high){
        int mid = (low+high)/2;
        int divi = divisor(arr,n,mid,t);
        if(divi<=t){
            res = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return res;
}

// -----------least capacity to ship packages within D days
int capacity(int arr[],int n,int c){
    int day = 1;
    int load = 0;
    for(int i=0;i<n;i++){
        if(load+arr[i]>c){
            day = day + 1;
            load = arr[i];
        } 
        else{
            load += arr[i];
        }
    }
    return day;
}
int ship(int arr[],int n,int d){
    int mini = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        mini = max(mini, arr[i]);
        sum += arr[i];
    }
    for(int i = mini;i<=sum;i++){
        int daysRequired = capacity(arr,n,i);
        if(daysRequired <= d){
            return i;
        }
    }
    return sum;
}

// -----------least capacity to ship packages within D days with B.S.
int ship_(int arr[],int n,int d){
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]); 
        sum += arr[i];
    }
    int low = maxi;
    int high = sum;
    int ans = sum;
    while(low<=high){
        int mid = (low+high)/2;
        int daysRequired = capacity(arr,n,mid);
        if(daysRequired<=d){
            ans = min(ans,mid);
            high = mid -1;
        }
        else{
            low = mid + 1;           
        }
    }
    return ans;
}

// -----------find kth missing number in sorted array
int missing(int arr[], int n, int k) {
    int missingCount = 0, index = 0, num = 1;  
    
    while (true) {
        if (index < n && arr[index] == num) {
            index++;  
        } else {
            missingCount++; 
            if (missingCount == k) return num; 
        }
        num++;
    }
}

// -----------find kth missing number in sorted array with B.S. ------slightly tough
int missing_(int arr[],int n,int k){
    int low = 0;
    int high = n-1;
    int missing = 0;
    while(low<=high){
        int mid = (low+high)/2;            // missing = arr[high] - (high + 1)   high is the index like mid
        missing = arr[mid] - (mid+1);      // ans = arr[high] + more 
        if(missing<k){                    // arr[high] + k - (arr[high] - high - 1)   => high + 1 + k same as => low + k as low = hihg + 1
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low + k;   // all the trick is in this lile
}

// ------------aggressive cows - place cow in stalls such that the minimum distance between the cows is maximum
bool canPlace(int stalls[],int n,int dis,int cow){
    int cnt = 1, lastCow = stalls[0];
    for(int i=1;i<n;i++){
        if(stalls[i]-lastCow>=dis){
            cnt++;
            lastCow = stalls[i];
        }
    }
    if(cnt>=cow) return true;
    else return false;
}
int cows(int stalls[],int n,int cow){
    sort(stalls,stalls+n);
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        mini = min(mini,stalls[i]);
        maxi = max(maxi,stalls[i]);
    }
    for(int i=1;i<(maxi-mini);i++){
        if(canPlace(stalls,n,i,cow) == true){
            continue;
        }
        else{
            return i-1;
        }
    }
}

// ------------aggressive cows with B.S.
int cows_(int stalls[],int n,int cows){
    sort(stalls,stalls+n);
    int low = 0;
    int high = stalls[n-1] - stalls[0];
    while(low<=high){
        int mid = (low+high)/2;
        if(canPlace(stalls,n,mid,cows)==true){
            low = mid + 1;
        }
        else{
            high = mid - 1; 
        }
    }
    return high;
}

// ---------------allocate books - such that every student get atleast one book and noone should have the same books
int noOfStudents(int pages[],int n,int page){
    int stud = 1;
    int pageStu = 0;
    for(int i=0;i<n;i++){
        if(pageStu + pages[i] <= page){
            pageStu += pages[i];
        }
        else{
            stud ++;
            pageStu = pages[i];
            }
    }
    return stud;
}
int books(int pages[],int n,int student){
    if(student>n){
        return -1;
    }
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        maxi = max(maxi,pages[i]);
        sum += pages[i];
    }
    int cntStudent = 0;
    for(int i=maxi;i<sum;i++){
        cntStudent = noOfStudents(pages,n,i);
        if(cntStudent == student){
            return i;
        }
    }
}

// ------------allocate books with B.S.
int books_(int pages[],int n,int student){
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        maxi = max(maxi,pages[i]);
        sum += pages[i];
    }
    int low = maxi;
    int high = sum;
    while(low<=high){
        int mid = (low+high)/2;
        if(noOfStudents(pages,n,mid)<=student){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    } 
    return low;                // in all these cases the low becomes higher than low and low stores the ans
}

// ------------painter's partition or split array - largest sum - this is exactly same as book allocation
int painters(int arr[],int n,int x){
    int number = 1;
    int units = 0;
    for(int i=0;i<n;i++){
        if(arr[i] + units<=x){
            units += arr[i];
        }
        else{
            number++;
            units = arr[i];
        }
    }
    return number;
}
int painter(int arr[],int n,int k){
    if(k>n) return -1;
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]);
        sum += arr[i];
    }
    int low = maxi;
    int high = sum;
    while(low<=high){
        int mid = (low+high)/2;
        if(painters(arr,n,mid)<=k){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

// ------------Tough question🥵🥴------------
// ------------maximise max distance to gas station -sorted
int gas(int arr[],int n,int k){

}

// ---------------median of two sorted array
int median(int arr[],int n,int arr1[],int n1){
    int n2 = n+n1;
    int arr2[n2];
    int i = 0, j = 0, k = 0;
    // merging the two sorted array
    while(i<n && j<n1){
        if(arr[i]>arr1[j]){
            arr2[k++] = arr1[j++];
        }
        else{
            arr2[k++] = arr[i++];
        }
    }
    while(i<n) {
        arr2[k++] = arr[i++];
    }
    while(j<n1){
        arr2[k++] = arr1[j++];
    }
    // calculating median
    int mdn;
    if(n2%2 == 0){
        mdn = (arr2[n2/2 - 1] + arr2[n2/2]) / 2;
    }
    else{
        mdn = arr2[n2/2];
    }
    return mdn;
}

// ------------median of two sorted array using optimisation
int median_(int arr[],int n,int arr1[],int n1){
    int cnt=0;
    int i = 0;
    int j = 0;
    int n2 = n + n1;
    int idx2 = n2/2;
    int idx1 = idx2 - 1;
    int idx1el = -1;
    int idx2el = -1;
    while(i < n && j<n1){
        if(arr[i]<arr1[j]){
            if(cnt == idx1) idx1el = arr[i];
            if(cnt == idx2) idx2el = arr[i];
            cnt++;
            i++;
        }
        else{
            if(cnt == idx1) idx1el = arr1[j];
            if(cnt == idx2) idx2el = arr1[j];
            cnt++;
            j++;
        }
    }
    while(i<n){
        if(cnt == idx1) idx1el = arr[i];
        if(cnt == idx2) idx2el = arr[i];
        cnt++;
        i++;
    }
    while(j<n1){
        if(cnt == idx1) idx1el = arr1[j];
        if(cnt == idx2) idx2el = arr1[j];
        cnt++;
        j++;
    }
    if(n%2 == 1){
        return idx2el;
    }
    else{
        return (idx1el + idx2el)/2;
    }
}

// ------------median of two sorted array using best optimisation
int median__(int arr[],int n,int arr1[],int n1){
    int 
}










int main() {
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int x;
    // cout<<"Enter the value of x: ";
    // cin>>x;


    // ------------lower bound - smallest index with arr[i] >= x 
    // lowerBound(arr,n,x);
    // cout<<endl;


    // ------------lower bound - smallest index with arr[i] >= x  with optimisation
    // cout<<"The smallest index is: "<<lowerBound_(arr,n,x);


    // -----------------this is a built in function in c++
    // int lb = lower_bound(arr,arr+n,x)-arr; 
    // cout<<"The smallest index is: "<<lb;


    // ---------------upper bound - smallest index with arr[i] > x
    // upperBound(arr,n,x);


    // ---------------upper bound - smallest index with arr[i] > x with optimisation
    // cout<<"The upper bound is: "<<upperBound_(arr,n,x);

    
    // -----------------this is a built in function in c++
    // int ub = upper_bound(arr,arr+n,x)-arr; 
    // cout<<"The smallest index is: "<<ub;


    // ----------------insert the element in an array at correct position
    // insertPosition(arr,n,x); 


    // ---------------floor in sorted array - floor - largest no.<=x 
    // floor(arr,n,x);


    // -------------ceil in sorted array - ceil - smallest no. >=x
    // ceil(arr,n,x);

    
    // -------------first and last occurence of x
    // occurence(arr,n,x);

    
    // -------------first and last occurence of x with optimisation
    // occurence_(arr,n,x);

    
    // ------------first occurence without using lower bound 
    // firstOccurence(arr,n,x);

    
    // ------------last occurence without using upper bound 
    // lastOccurence(arr,n,x);


    // ------------search in rotated array
    // rotatedSearch(arr,n,x);


    // ------------search in rotated sorted array with duplicates element present
    // cout<<"Is the element present: "<<rotatedSearchDuplicates(arr,n,x);
    

    // --------------minimum in the rotated sorted array
    // cout<<"The minimum element is: "<<minimumInRotated(arr,n);


    // -----------minimum in the rotated sorted array with duplicates
    // cout<<"The minimum element is: "<<minimumInRotatedDuplicates(arr,n);

    
    // -------------number of times array rotated
    // cout<<"The number of times array rotated is: "<<rotatedNumber(arr,n);


    // -------------number of times array rotated with duplicates
    // cout<<"The number of times array rotated is: "<<rotatedNumberDuplicates(arr,n);


    // ------------single element in sorted duplicates array - having exactly two time a number
    // cout<<"The single element is: "<<singleElement(arr,n);


    // ------------single element in a sorted array using optimisation
    // cout<<"The single element is: "<<singleElement_(arr,n);

    
    // -------------peak element - arr[i-1] < arr[i] > arr[i+1]
    // cout<<"The peak element is: "<<peakElement(arr,n);

    
    // -----------peak element with B.S.
    // cout<<"The peak element is: "<<peakElement_(arr,n);


    // -----------sqrt of an interger
    // cout<<"The square root is: "<<sqrt(n);


    // -----------sqrt of an interger with B.S.
    // cout<<"The square root is: "<<sqrt_(n);


    // int m;
    // cin>>m; 

    // -----------find nth root of an integer m
    // cout <<"The "<< m << " root of " << n << " is: " << root(n,m);


    // ----------find the nth root with B.S.
    // cout <<"The "<<m<<" root of "<<n<<" is: "<< root_(n,m);

    
    // int h;
    // cin>>h;
    // ---------koko eating bananas - minimum bananas/hr to eat all bananas with h hrs
    // cout<<"The number of bananas/hr is: "<<koko(arr,n,h);


    // -----------koko eating bananas - minimum bananas/hr to eat all bananas with h hrs with B.S.
    // cout<<"The number of bananas/hr is: "<<koko_(arr,n,h);

    
    // ------------minimum number of days to make M bouquets with bloomed flowers
    // int m,k;
    // cin>>m>>k;
    // cout<<"The minimum days to make m bouquets is: "<<bouquets(arr,n,m,k);

    
    // ------------minimum number of days to make M bouquets with bloomed flowers
    // cout<<"The minimum days to make m bouquets is: "<<bouquets_(arr,n,m,k);

    
    // --------------find the smallest divisor given a threshold
    // int t;
    // cin>>t; 
    // cout<<"The smallest divisor is: "<<threshold(arr,n,t);
    
    
    // --------------find the smallest divisor given a threshold with B.S.
    // cout<<"The smallest divisor is: "<<threshold_(arr,n,t);
    

    // -----------least capacity to ship packages within D days
    // int d;
    // cin>>d;
    // cout<<"The least capacity is: "<<ship(arr,n,d);


    // -----------least capacity to ship packages within D days with B.S.
    // cout<<"The least capacity is: "<<ship_(arr,n,d);

    
    // -----------find kth missing number in array
    // int k;
    // cin>>k;
    // cout<<"The kth missing number is: "<<missing(arr,n,k);


    // -----------find kth missing number in array with B.S.
    // cout<<"The kth missing number is: "<<missing_(arr,n,k);


    // ----------aggressive cows
    // int cow;
    // cin>>cow;
    // cout<<"The minimum distance is: "<<cows(arr,n,cow);


    // ------------book allocation
    // int student;
    // cin>>student;
    // cout<<"The maximum pages are: "<<books(arr,n,student);


    // ------------book allocation
    // cout<<"The maximum pages are: "<<books_(arr,n,student);


    // -------------painters problem same as book allocation
    // int k;
    // cin>>k;
    // cout<<"The maximum units are: "<<painter(arr,n,k);






    
    // ---------------median of two sorted array
    int n1;
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    // cout<<"The median of two sorted array are: "<<median(arr,n,arr1,n1);

    
    // ---------------median of two sorted array with optimisation
    // cout<<"The median of two sorted array are: "<<median_(arr,n,arr1,n1);









    return 0;
}