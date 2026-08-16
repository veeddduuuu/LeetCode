class Solution {
public:
    void dfs(int n, int k, int i, vector<string> &ans, string s){
        if(i == n){
            int cost = 0;
            for(int i = 0; i<n; i++){
                if(s[i] == '1') cost+=i;
            }
            if(cost<=k) ans.push_back(s);
            return;
        }
        s.push_back('0');
        dfs(n, k, i + 1, ans, s);
        s.pop_back();
        if(s.empty() || s.back()!='1'){
            s.push_back('1');
            dfs(n, k, i + 1, ans, s);
            s.pop_back();
        }
    }
    
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        string s = "";
        dfs(n, k, 0, ans, s);
        return ans;
    }
};