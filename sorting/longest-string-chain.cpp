class Solution {
public:
    bool compare(string a, string b){
        int n = a.size();
        int m = b.size();
        if(n!=m+1) return false;
        int i = 0, j = 0;
        while(i<n and j<m){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else i++;
        }
        return j == m;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        int lis = 0;
        
        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.size()<b.size();
        });

        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(compare(words[i], words[j])){
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }
            lis = max(lis, dp[i]);
        }
        return lis;
    }
};