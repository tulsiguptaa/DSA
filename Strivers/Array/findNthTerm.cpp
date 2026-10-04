#include <bits/stdc++.h>
using namespace std;

void findNthTerm(int n){
    if(n % 2 == 1){
        cout<<pow(2, n/2)<<endl;
    }
    else{
        cout<< pow(3, n/3)<<endl;
    }
}

int main() {
    int N = 4;
    findNthTerm(N);

    N = 11;
    findNthTerm(N);
    return 0;
}