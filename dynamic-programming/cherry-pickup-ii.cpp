class Solution {
public:
    int func(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
        if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size()){
            return  -1e8;
        }
        if(i == grid.size()-1){
            return j1==j2 ? grid[i][j1] : grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi = -1e8;
        for(int x = -1; x<=1; x++){
            for(int y = -1; y<=1; y++){
                int val = 0;
                if(j1==j2) val = grid[i][j1];
                else val = grid[i][j1]+grid[i][j2];
                val+=func(i+1, j1+x, j2+y, grid, dp);
                maxi = max(maxi, val);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return func(0, 0, grid[0].size()-1, grid, dp);
    }
};