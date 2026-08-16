#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll, ll>>> adj(n);
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        ll mod = 1e9+7;

        vector<ll> dist(n, LLONG_MAX);
        vector<ll> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                ll adjDis = it.second;
                ll adjNode = it.first;
                if(adjDis+dis < dist[adjNode]){
                    pq.push({adjDis+dis, adjNode});
                    dist[adjNode] = adjDis+dis;
                    ways[adjNode] = ways[node];
                }
                else if(adjDis+dis == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return int(ways[n-1]);
    }
};