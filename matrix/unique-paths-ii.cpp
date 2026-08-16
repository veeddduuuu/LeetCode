class Solution {
public:
    vector<vector<int>> dp;
    int func(int i, int j, vector<vector<int>> &grid){
        if(i<0 || j<0) return 0;
        if(grid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = func(i-1, j, grid);
        int left = func(i, j-1, grid);
        return dp[i][j] = up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int n = obstacleGrid.size();
       int m = obstacleGrid[0].size();
       dp.assign(n+1, vector<int>(m+1, 0));
    //    return func(n-1, m-1, obstacleGrid);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 0 && j == 0){
                    dp[0][0] = 1; continue;
                }
                int up = 0, left = 0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j] = up+left;
            }
        }
        return dp[n-1][m-1];
    }
};