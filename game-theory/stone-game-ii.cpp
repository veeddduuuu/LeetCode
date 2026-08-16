class Solution {
public:
    int n;
    vector<int> suff;
    vector<vector<int>> dp;
    int f(int i, int m){
        if(i == n) return 0;
        if(dp[i][m] != -1) return dp[i][m];

        int best = 0;
        for(int x = 1; x<=2*m and i+x<=n; x++){
            int next = max(m, x);
            int curr = suff[i] - f(i+x, next);
            best = max(best, curr);
        }
        return dp[i][m] = best;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suff.assign(n+1, 0);
        for(int i = n-1; i>=0; i--){
            suff[i] = suff[i+1]+piles[i];
        }
        dp.assign(n, vector<int>(n+1, -1));
        return f(0, 1);
    }
};