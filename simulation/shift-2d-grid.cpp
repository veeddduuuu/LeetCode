class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int t =  m*n;

        k %= t;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int old = i * n + j;
                int neww = (old + k) % t;
                int nr = neww / n;
                int nc = neww % n;
                ans[nr][nc] = grid[i][j];
            }
        }
        return ans;
    }
};