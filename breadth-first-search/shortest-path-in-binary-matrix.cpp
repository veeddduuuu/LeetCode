class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        if(grid[0][0] == 1) return -1;
        q.push({1, {0, 0}});
        dist[0][0] = 1;
        vector<int> dr = {1, -1, 0, 0, 1, 1, -1, -1};
        vector<int> dc = {0, 0, 1, -1, 1, -1, 1, -1};
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int nodeDist = node.first;
            int r = node.second.first;
            int c = node.second.second;
            for(int i = 0; i<8; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 0){
                    if(nodeDist+1 < dist[nr][nc]){
                        dist[nr][nc] = nodeDist+1;
                        q.push({nodeDist+1, {nr, nc}});
                    }
                }
            }
        }
        return dist[n-1][n-1] == 1e9 ? -1 : dist[n-1][n-1];

    }
};