class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& vis,vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();
        if(i>=m || i<0 || j>=n || j<0 || board[i][j] == 'X' || vis[i][j] == true ) return;
        vis[i][j] = true;
        dfs(i+1, j, vis, board);
        dfs(i-1, j, vis, board);
        dfs(i, j+1, vis, board);
        dfs(i, j-1, vis, board);
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i = 0; i<n; i++){
            if(board[m-1][i] == 'O'){
                    dfs(m-1,i,vis, board);
            }
        }

        for(int i = 0; i<n; i++){
            if(board[0][i] == 'O'){
                dfs(0,i,vis, board);
            }
        }


        for(int i = 0; i<m; i++){
            if(board[i][0] == 'O'){
                dfs(i,0,vis, board);
            }
        }

        for(int i = 0; i<m; i++){
            if(board[i][n-1] == 'O'){
                dfs(i,n-1,vis, board);
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }    
    }
};