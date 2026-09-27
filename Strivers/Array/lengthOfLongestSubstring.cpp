#include <bits/stdc++.h>
using namespace std;

// Brute
int lengthOfLongestSubstring(string s) {
        map<char, int> mpp;
        int maxi = 0;
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i]) == mpp.end()){
                mpp[s[i]] = 1;
                cnt ++;
                maxi = max(maxi, cnt);
            }
            else {
                mpp.clear();
            cnt = 0;
            mpp[s[i]] = 1;
            cnt++;
            }
            
        }
        return maxi;
}

// Optimal


int main() {
     string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Length of longest substring without repeating characters: "<< lengthOfLongestSubstring(s) << endl;
    cout << "Length of longest substring without repeating characters: "<< lengthOfLongestSubstring_(s) << endl;
    return 0;
}