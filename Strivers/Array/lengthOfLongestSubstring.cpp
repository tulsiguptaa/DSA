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
int lengthOfLongestSubstring_(string s) {
        map<char, int> mpp;
        int left = 0;
        int maxi = 0;

        for (int right = 0; right < s.size(); right++) {

            if (mpp.find(s[right]) != mpp.end()) {
                left = max(left, mpp[s[right]] + 1);
            }

            mpp[s[right]] = right;

            maxi = max(maxi, right - left + 1);
        }
        return maxi;
}

int main() {
     string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Length of longest substring without repeating characters: "<< lengthOfLongestSubstring(s) << endl;
    cout << "Length of longest substring without repeating characters: "<< lengthOfLongestSubstring_(s) << endl;
    return 0;
}