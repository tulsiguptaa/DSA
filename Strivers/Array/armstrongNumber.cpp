#include <bits/stdc++.h>
using namespace std;

bool armstrongNumber(int n) {    
    int num = n;
    int len = to_string(n).length();
    int res = 0;
    while (num > 0) {
        int rem = num % 10;
        int power = 1;
        for (int i = 0; i < len; i++) {
            power *= rem;
        }
        res += power;
        num /= 10;
    }
    return n == res;
}
int main() {
    int n;
    cout<<"Enter the val of n: ";
    cin>>n;

    cout<<armstrongNumber(n);
    return 0;
}