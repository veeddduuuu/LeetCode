class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> minDistArr(n + 1, INT_MAX);
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); i++) {
            int a = times[i][0];
            int b = times[i][1];
            int c = times[i][2];
            adj[a].push_back({b, c});
        }
        q.push({0, k});
        minDistArr[k] = 0;
        while (!q.empty()) {
            auto [nodeDist, node] = q.top();
            q.pop();
            // if (minDistArr[node] < nodeDist)
                // continue;
            for (auto [neigh, neighDist] : adj[node]) {
                if (minDistArr[neigh] > nodeDist + neighDist) {
                    q.push({nodeDist + neighDist, neigh});
                    minDistArr[neigh] = nodeDist + neighDist;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i<=n; i++) {
            ans = max(minDistArr[i], ans);
            if (minDistArr[i] == INT_MAX)
                return -1;
        }
        return ans;
    }
};