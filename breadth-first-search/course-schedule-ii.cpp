class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for(int i = 0; i<prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            graph[b].push_back(a);
            inDegree[a]++;
        }

        vector<int> ans;
        queue<int> q;
        
        for(int i = 0; i<inDegree.size(); i++){
            if(inDegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int src = q.front();
            q.pop();
            ans.push_back(src);
            for(auto node:graph[src]){
                inDegree[node]--;
                if(inDegree[node] == 0) q.push(node);
            }
        }
        return ans.size()==numCourses?ans:vector<int>();

    }
};