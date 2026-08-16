class Solution {
public:
    bool bfs(int u, vector<int> &color, vector<vector<int>> &adj){
        queue<int> q;
        q.push(u);
        color[u] == 0; 
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto adjNode : adj[node]){
                if(color[adjNode] == -1){
                    color[adjNode] = !color[node];
                    q.push(adjNode);
                }
                if(color[adjNode] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for(int i = 0; i<graph.size(); i++){
            if(color[i] == -1 && !bfs(i, color, graph)) return false;
        }

        return true;
    }
}; 