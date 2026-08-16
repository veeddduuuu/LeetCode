class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int,pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> diff(n, vector<int> (m, 1e9));
        pq.push({0, {0, 0}});
        diff[0][0] = 0;
        vector<int> dr = {0, 0, 1, -1};
        vector<int> dc = {1, -1, 0, 0};
        while(!pq.empty()){
            auto node = pq.top();
            int effort = node.first;
            int r = node.second.first;
            int c = node.second.second;
            pq.pop();
            if(r == n-1 && c == m-1) return effort;
            for(int i = 0; i<4; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int newEffort = max(abs(heights[r][c] - heights[nr][nc]), effort);
                    if(newEffort < diff[nr][nc]){
                        diff[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                    // if(abs(heights[r][c] - heights[nr][nc]) > diff[nr][nc]){
                    //     q.push(abs({heights[r][c] - heights[nr][nc]), {nr, nc}});
                    //     diff[nr][nc] = abs(nodeDiff - grind[nr][nc]);
                    // }
                }
            }
        }
        return diff[n-1][m-1];
    }
};