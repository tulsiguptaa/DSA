#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int maxi = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        int cnt = 0;
        while(sum < amount){
            sum += coins[i];
            cnt ++;
        }
        if(sum == amount) maxi = max(maxi, cnt);
    }  
    return maxi;
}


int main() {
    int n;
    cout<<"Enter the val of n: ";
    cin>>n;

    int coins[n];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }


    return 0;
}