#include <bits/stdc++.h>
using namespace std;

// -------------bit manipulation-------------


// ---------decimal to binary
void decimalToBinary(int n){
    int binary = 0, place = 1;
    while (n > 0) {
        int rem = n % 2;
        binary = binary + rem * place;
        n = n / 2;
        place = place * 10;
    }
     cout << "Binary: " << binary << endl;
}

// -----------decimal to binary using string
string decimalToBinary_(int n){
    string res = "";
    while(n>0){
        if(n%2 == 1) res += '1';
        else res += '0';
        n = n/2;
    }
    reverse(res.begin(), res.end());
    return res;
}

// -----------binary to decimal
void binaryToDecimal(int n){
    int place = 0;
    int res = 0;
    while(n!=0){
        int remain = n%10;
        res += remain*(pow(2,place));
        place++;
        n = n/10;
    }
    cout<<"Decimal is: "<<res;
}

// ------------binary to decimal using string
void binaryToDecimal_(string n){
    int len = n.length();
    int num = 0;
    int p2 = 1;
    for(int i=len-1;i>0;i--){
        if(n[i] == '1'){
            num = num + p2;
        }
        p2 = p2 *2;
    }
    cout<<"The decimal is: "<<num;
}

// --------------swap two numbers
void swap(int n1, int n2){
    n1 = n1^n2;
    n2 = n1^n2;
    n1 = n1^n2;
    cout<<"N1 is: "<<n1<<endl;
    cout<<"N2 is: "<<n2;
}

// ------------check if the ith bit is set or not - using left shift
void checkIth(int n, int i){
    if ((n & (1 << i)) != 0) {
        cout << "Set" << endl;
    } else {
        cout << "Not set" << endl;
    }
}

// ------------check if the ith bit is set or not - using right shift 
void checkIth_(int n, int i){
    if((1 & (n >> i)) != 0){
        cout<<"Set"<<endl;
    }
    else{
        cout<<"Not Set"<<endl;
    }
}

// -------------set the ith bit
int setIth(int n, int i){
    n = (n|(1<<i));
    return n;
}

// -------------clear the ith bit
int clearIth(int n, int i){
    n = n &(~(1<<i));
    return n;
}

// ------------toggle the ith bit
int toggleIth(int n,int i){
    n = n^(1<<i);
    return n;
}

// ------------remove the last set bit
int removeLast(int n){
    n = n & (n-1);
    return n;
}

// -----------check if a number is power of 2 ---------if there is only one set bit (100,01000)
void power2(int n){
    if((n & (n-1)) == 0){
        cout<<"Yes! ";
    }
    else{
        cout<<"No";
    }
}

// --------------count number of set bits
int countSet(int n){
    int cnt = 0;
    while(n>1){
        int rem = n%2;
        if(rem == 1){
            cnt++;
        }
        n = n/2;
    }
    if(n == 1) cnt++;
    return cnt;
}

// --------------count number of set bits slight different
int countSet_(int n){
    int cnt = 0;
    while(n>1){
        int rem = n&1;   // as the last bit of every odd number is 1 (checks odd)
        if(rem == 1){
            cnt++;
        }
        n = n>>1;      // as right shift is divide by 2
    }
    if(n == 1) cnt++;
    return cnt;
}

// ------------count number of set bits differnt way
int countSet__(int n){
    int cnt = 0;
    while(n!=0){
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}

// ------------minimum number of bits required to convert a number
int minimumBit(int start, int goal){
    int res = start ^ goal;
    return countSet__(res);
}

// ---------------power set
vector<vector<int>> powerSet(vector<int> arr, int n){
    int subsets = 1<<n;     // 2^n
    vector<vector<int>> li;
    for(int i=0;i<subsets;i++){
        vector<int> items;
        for(int j=0;j<n;j++){
            if((i & (1<<j)) != 0){   
                items.push_back(arr[j]);
            }
        } 
        li.push_back(items);
    }
    return li;
}

// --------------single number in array
int singleNum(int arr[], int n){
    int res = arr[0];
    for(int i=1;i<n;i++){
        res = arr[i] ^ res;
    }
    return res;
}

// ---------------single number in array having all other 3 times --- slight tough 😔
int singleNum_(int arr[],int n){
    int ans = 0;
    for(int bitIndx = 0; bitIndx<=31;bitIndx++){
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(arr[i] & (1<<bitIndx)){
                cnt++;
            }
        }
        if(cnt%3 == 1){
            ans = ans | (1<<bitIndx);
        }
    }
    return ans;
}

// -------------single number in array having all other 3 
int singleNum__(int arr[],int n){
    sort(arr,arr+n);
    for(int i=1;i<n;i = i+3){
        if(arr[i] != arr[i-1]){
            return arr[i-1];
        }
    }
    return arr[n-1];
}

// -------------single number in array having all other 3  - best optimisation
int singleNum___(int arr[],int n){
    int ones = 0;
    int twos = 0;
    for(int i=0;i<n;i++){
        ones = (ones ^ arr[i]) & ~ twos;
        twos = (twos ^ arr[i]) & ~ ones;
    }
    return ones;
}

// -------------single number in array having all other 2 and single 2 - tough
pair<int, int> singleNum____(int arr[], int n){
    int XOR = 0;
    for(int i=0;i<n;i++){
        XOR = XOR ^ arr[i];
    }
    int rightmost = (XOR & (XOR-1)) ^ XOR;
    int bit1 = 0;
    int bit2 = 0;
    for(int i=0;i<n;i++){
        if(arr[i] & rightmost){
            bit1 = bit1^arr[i];
        }
        else{
            bit2 = bit2 ^ arr[i];
        }
    }
    return {bit1,bit2};
}

// -------------XOR of number from 1 to n
int XOR(int n){
    int res = 0;
    for(int i=0;i<=n;i++){
        res = res ^ i;
    }
    return res;
}

// ------------XOR of number from 1 to n with optimisation
int XOR_(int n){
    if(n%4 == 1){
        return 1;
    }
    else if(n%4 == 2){
        return n+1;
    }
    else if(n%4 == 3){
        return 0; 
    }
    else{
        return  n;
    }
}

// --------------XOR of number in a given range with optimisation
int XOR__(int l, int h){
    int lower = XOR_(l-1);
    int higher = XOR_(h);
    return lower ^ higher;
}

// ---------------divide two integers without division operator
int division(int dividend, int divisor){
    int sum = 0;
    int cnt = 0;
    while(sum + divisor <= dividend){
        cnt = cnt+1;
        sum += divisor;
    }
    return cnt;
}

// ---------------divide two integers without division operator
int division_(int dividend, int divisor){
    if(dividend == divisor) return 1;
    bool sign = true;   // +ve
    if(dividend >= 0 && divisor<0) sign = false;
    if(dividend < 0 && divisor>0) sign = false;
    int n = abs(dividend);
    int d = abs(divisor);
    int ans = 0;
    while(n>=d){
        int cnt = 0;
        while(n>=(d*pow(2,cnt+1))){
            cnt++;
        }
        ans += (1<<cnt);
        n -= (d<<cnt);
    }
    return ans;
}



int main() {
    // int n;
    // cout<<"Enter the value of n: ";
    // cin>>n;

    // string n;
    // cout<<"Enter the value of n: ";
    // cin>>n;

    // decimalToBinary(n);

    // cout<<decimalToBinary_(n);

    // binaryToDecimal(n);

    // binaryToDecimal_(n);

    // cout<<"Bitwise AND operation: "<<(5 & 9)<<endl;
    // cout<<"Bitwise OR operation: "<<(5 | 9)<<endl;
    // cout<<"Bitwise NOT operation: "<<(~5)<<endl;
    // cout<<"EXOR operation: "<<(5 ^ 9)<<endl;

    // swap(5,7);

    // int i;
    // cout<<"Enter the value of i: ";
    // cin>>i;
    int n1;
    cout<<"Enter the value of n1: ";
    cin>>n1;
    int n2;
    cout<<"Enter the value of n2: ";
    cin>>n2;
    // checkIth(n1,i);

    // checkIth_(n1,i);

    // cout<<"Result is: "<<setIth(n1, i);

    // cout<<"Result is: "<<clearIth(n1,i);

    // cout<<"Result is: "<<toggleIth(n1,i);

    // cout<<"Result is: "<<removeLast(n1);

    // power2(n1);

    // cout<<"The number of set bits are: "<<countSet(n1);

    // cout<<"The number of set bits are: "<<countSet_(n1);
    
    // cout<<"The number of set bits are: "<<countSet__(n1);

    // cout<<__builtin_popcount(n1);    // built in funciton to count number of set bit

    // cout<<"The minimum bits are: "<<minimumBit(n1,n2);

    // vector<int> arr = {1, 2, 3};
    // vector<vector<int>> subsets = powerSet(arr, arr.size());
    // for (auto subset : subsets) {
    //     cout << "{ ";
    //     for (int x : subset) cout << x << " ";
    //     cout << "}" << endl;
    // }

    // int arr[10] = {1,1,4,3,3,8};
    // cout<<"The single number is: "<<singleNum(arr,5);

    // cout<<"The single number is: "<<singleNum_(arr,10);

    // cout<<"The single number is: "<<singleNum__(arr,10);

    // cout<<"The single number is: "<<singleNum___(arr,10);

    // pair<int, int> result = singleNum____(arr, 10);
    // cout << "The two single numbers are: " << result.first << " and " << result.second << endl;

    // cout<<"The XOR is: "<<XOR(n1);

    // cout<<"The XOR is: "<<XOR_(n1);

    // cout<<"The XOR is: "<<XOR__(n1,n2);

    // cout<<"The result is: "<<division(n1,n2);

    // cout<<"The result is: "<<division_(n1,n2);




    return 0;
}