class Solution {
private:
    void helper(int ind, int n, string &digits, vector<string> &combo, string temp, vector<string> &ans){
        if(ind == n){
            ans.push_back(temp);
            return;
        }

        int num = digits[ind] - '0';

        for(int i = 0; i<combo[num].size(); i++){
            helper(ind+1, n, digits, combo, temp+combo[num][i], ans);
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        string temp;
        vector<string> ans;
        vector<string> combo = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        helper(0, n, digits, combo, temp, ans);
        return ans;
    }
};