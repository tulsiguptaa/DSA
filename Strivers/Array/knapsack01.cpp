#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int maxi = 0;
    for(i=0;i<val.size();i++){
        int res =  val[i] /wt[i] ;
        if(wt[i] <= W){
            maxi  = max(maxi, res);
        }
    }
        
}

int main() {
    
    return 0;
}