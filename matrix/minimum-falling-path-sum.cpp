class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int j = 0; j < n; j++)
            dp[0][j] = matrix[0][j];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int up = matrix[i][j] + dp[i - 1][j];

                int leftDiag = matrix[i][j];
                if (j > 0)
                    leftDiag += dp[i - 1][j - 1];
                else
                    leftDiag += 1e9;

                int rightDiag = matrix[i][j];
                if (j < n - 1)
                    rightDiag += dp[i - 1][j + 1];
                else
                    rightDiag += 1e9;

                dp[i][j] = min({up, leftDiag, rightDiag});
            }
        }

        int ans = 1e9;
        for (int j = 0; j < n; j++)
            ans = min(ans, dp[n - 1][j]);

        return ans;
    }
};