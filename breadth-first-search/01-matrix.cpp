class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        queue<pair<int, int>> q;
        
        vector<vector<int>> ans(m, vector<int>(n, -1));

        for (int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<int> row = {-1, 1, 0, 0};
        vector<int> col = {0, 0, -1, 1};
        int dist = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i<size; i++){
                auto [r, c] = q.front();
                q.pop();
                for(int k = 0; k<4; k++){
                    int newr = r+row[k];
                    int newc = c+col[k];
                    if(newr>=0 && newr<m && newc>=0 && newc<n && ans[newr][newc] == -1 && mat[newr][newc] == 1){
                        q.push({newr, newc});
                        ans[newr][newc] = dist;
                    }
                }
            }
            dist++;
        }

        return ans;
    }
};