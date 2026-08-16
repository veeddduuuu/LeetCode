class Solution{
public:
    // bool isValid(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid){
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     if(i>=0 && j>=0 && i<n && j<m && vis[i][j] == false && grid[i][j] == '1') return true;
    //     return false;
    // }

    void dfs(int i, int j, vector<vector<char>> &grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] != '1') return;
        // vis[i][j] = true;
        grid[i][j] = '0';
        // vector<int> di = {0,0,1,-1};
        // vector<int> dj = {1,-1,0,0};

        // for(int k = 0; k<4; k++){
        //     dfs(i+di[k], j+dj[k], grid);
        // }

        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);

        return;

        // if(isValid(i+1, j, vis, grid)){
        //     dfs(i+1, j, vis, grid);
        // }
        // if(isValid(i+1, j+1, vis, grid)){
        //     dfs(i+1, j+1, vis, grid);
        // }
        // if(isValid(i+1, j-1, vis, grid)){
        //     dfs(i+1, j-1, vis, grid);
        // }
        // if(isValid(i, j+1, vis, grid)){
        //     dfs(i, j+1, vis, grid);
        // }
        // if(isValid(i, j-1, vis, grid)){
        //     dfs(i, j-1, vis, grid);
        // }
        // if(isValid(i-1, j-1, vis, grid)){
        //     dfs(i-1, j-1, vis, grid);
        // }
        // if(isValid(i-1, j, vis, grid)){
        //     dfs(i-1, j, vis, grid);
        // }
        // if(isValid(i-1, j+1, vis, grid)){
        //     dfs(i-1, j+1, vis, grid);
        // }
        // return;
    }

    int numIslands(vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        // vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
