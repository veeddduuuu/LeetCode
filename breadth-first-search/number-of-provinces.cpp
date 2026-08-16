class Solution {
public:
    
    void dfs(int u, int n, vector<vector<int>> &adj, vector<bool> &vis){
        vis[u] = true;
        for(int v = 0; v<n; v++){
            if(!vis[v] && adj[u][v] == 1){
                dfs(v, n, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
       int n = isConnected.size();
        int cnt = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i, n, isConnected, vis);
                cnt++;
            }
        }
        return cnt; 
    }
};