class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        
        vector<int> ans;
        queue<int> q;       
        int n = graph.size();

        vector<vector<int>> revGraph(n);
        vector<int> indegree(n, 0);

        for(int i = 0; i<n; i++){
            for(auto j : graph[i]){
                revGraph[j].push_back(i);
            } 
            indegree[i] = graph[i].size();
        }

        for(int i = 0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto neigh : revGraph[node]){
                indegree[neigh]--;
                if(indegree[neigh] == 0) q.push(neigh);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};