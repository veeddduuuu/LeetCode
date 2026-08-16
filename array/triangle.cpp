class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int j, vector<vector<int>> &arr){
        if(i<0||j>i||j<0) return 1e9;
        if(i==0 && j==0) return arr[0][0];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] =  arr[i][j]+min(f(i-1, j, arr), f(i-1, j-1, arr));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        int ans = INT_MAX;
        dp.assign(n, vector<int>(m, -1));
        for(int i = 0; i<m; i++){
            int temp = f(n-1, i, triangle);
            ans = min(ans, temp);
        }
        return ans;
    }
};