class Solution {
public:
    vector<int> dp;
    bool f(int n){
        if (n == 0) return false;
        if(dp[n] != -1) return dp[n] == 1 ? true : false;
        for(int k = 1; k*k<=n; k++){
            if(f(n-k*k) == false) return dp[n] = true;
        }
        return dp[n] = false;

    }
    bool winnerSquareGame(int n) {
        dp.assign(n+1, -1);
        return f(n);
    }
};