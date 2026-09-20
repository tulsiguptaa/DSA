#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;
    for(int i=0;i<s.size();i++){
        bool check = false;
        for(int j=0;j<t.size();j++){
            if(s[i] == t[j]) check = true;
        }
        if(check == false) return false;
    }
    return true;
}

 bool isAnagram_(string s, string t) {
     if(s.size() != t.size()) return false;
    map<char, int> mpp, mpp1;
    for(int i=0;i<s.size();i++){
        mpp[s[i]]++;
    }
    for(int i=0;i<t.size();i++){
        mpp1[t[i]]++;
    }
    return mpp == mpp1; 
}

 bool isAnagram__(string s, string t) {
    if(s.size() != t.size()) return false;
    int hash[26] = {0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }
    for(int i=0;i<t.size();i++){
        hash[t[i]-'a']--;
    }
    for(int i = 0; i < 26; i++) {
        if(hash[i] != 0) return false;
    }
    return true;
}

int main() {
    string s;
    string t;
    cout<<"Enter a string s: ";
    getline(cin, s);
    cout<<"Enter a string t: ";
    getline(cin, t);

    cout<<isAnagram(s,t)<<"\n";
    cout<<isAnagram_(s,t)<<"\n";
    cout<<isAnagram__(s,t)<<"\n";

    return 0;
}