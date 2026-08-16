class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int j, vector<int>& piles){
        if(i == j) return dp[i][i] = piles[i];
        if(dp[i][j]!=-1) return dp[i][j];
        int pick = piles[i] - f(i+1, j, piles);
        int notPick = piles[j] - f(i, j-1, piles);
        return dp[i][j] = max(pick, notPick);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n, -1));
        int ans = f(0, n-1, piles);
        return ans;      
    }
};