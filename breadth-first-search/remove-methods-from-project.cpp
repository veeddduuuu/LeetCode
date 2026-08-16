class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);

        for(auto edge : invocations){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
        }

        unordered_set<int> st;
        queue<int> q;

        st.insert(k);
        q.push(k);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto next : graph[node]){
                if(st.count(next)) continue;

                st.insert(next);
                q.push(next);
            }
        }

        for(auto edge : invocations){
            int u = edge[0];
            int v = edge[1];

            if(!st.count(u) && st.count(v)){
                vector<int> ans;
                for(int i = 0; i < n; i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }

        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(!st.count(i)){
                ans.push_back(i);
            }
        }

        return ans;
    }
};