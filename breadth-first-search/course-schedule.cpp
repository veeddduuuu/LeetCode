class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // vector<int> topoSort;
        int cnt=0;
        queue<int> q;
        vector<int> inDegree(numCourses);
        vector<vector<int>> graph(numCourses);
        for(int i = 0; i<prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            graph[b].push_back(a);
            inDegree[a]++;
        }

        for(int i = 0; i<inDegree.size(); i++){
            if(inDegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int src = q.front();
            q.pop();
            cnt++;
            for(auto node : graph[src]){
                inDegree[node]--;
                if(inDegree[node] == 0) q.push(node);
            }
        }
        if(cnt == numCourses) return true;
        return false;
    }
};