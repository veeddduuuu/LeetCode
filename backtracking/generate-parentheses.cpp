class Solution {
private:
    void helper(int open, int close, int n, string s, vector<string> &ans){
        if(open == close && (open+close) == 2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            helper(open+1, close, n, s+'(', ans);
        }

        if(close<open){
            helper(open, close+1, n, s+')', ans);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";

        helper(0, 0, n, s, ans);
        return ans;        
    }
};