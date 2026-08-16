class Solution {
public:
    int func(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == 0 && j == 0){
            return grid[0][0];
        }
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=grid[i][j]+min(func(i-1, j, grid, dp), func(i, j-1, grid, dp));
    
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // return func(m-1, n-1, grid, dp);
        dp[0][0] = grid[0][0];
        for(int i = 0; i<m; i++){
            for(int j = 0;  j<n; j++){
                if(i==0 & j==0) continue;
                int left = (j>0) ? dp[i][j-1] : 1e9;
                int up = (i>0) ? dp[i-1][j] :  1e9;
                dp[i][j] = grid[i][j]+ min(left, up);
            }
        }
        return dp[m-1][n-1];
    }
};