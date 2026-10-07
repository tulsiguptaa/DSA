#include <bits/stdc++.h>
using namespace std;

vector<string> fun(int n, stack<string> st){
    vector<string> ans;
    if(n<1) return ans;
    fun(n-1, st.psuh('('));
    ans.push_back(st.top());
    st.pop();
    fun(n, st);
    return ans;
}


vector<string> generateParenthesis(int n) {
    stack<int> st;
    fun(n, st);
}

class Solution {
public:
    vector<string> ans;

    void fun(int n, int open, int close, string path) {
        if (path.size() == 2 * n) {
            ans.push_back(path);
            return;
        }
        if (open < n) {
            fun(n, open + 1, close, path + '(');
        }
        if (close < open) {
            fun(n, open, close + 1, path + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        fun(n, 0, 0, "");
        return ans;
    }
};

int main() {
    
    return 0;
}