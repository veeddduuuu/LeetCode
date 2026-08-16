class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        int freshOranges = 0;
        // int rottenOranges = 0;
        queue<pair<int, int>> q;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    freshOranges++;
                }
                if(grid[i][j]==2){
                    q.push({i, j});
                    // rottenOranges++;
                }
            }
        }

        vector<int> row = {-1, 1, 0, 0};
        vector<int> col = {0, 0, -1, 1};

        while(!q.empty() && freshOranges>0){
            int size = q.size();
            for(int i = 0; i<size; i++){
                auto [r, c] = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int newr = r+row[k];
                    int newc = c+col[k];
                    if(newr<n && newr>=0 && newc<m && newc>=0 && grid[newr][newc] == 1){
                        grid[newr][newc] = 2;
                        q.push({newr,newc});
                        freshOranges--;
                    }                    
                }
            }
            time++;
        }
        return freshOranges==0?time:-1;    
    }
};