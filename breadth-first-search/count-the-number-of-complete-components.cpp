class DisjointSet{
    vector<int> parent;
    vector<int> size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }
    int find(int n){
        if(parent[n] == n) return n;
        return parent[n] = find(parent[n]);
    }
    void unionBySize(int u, int v){
        int rootu = find(u);
        int rootv = find(v);
        if(rootu == rootv) return;
        if(size[rootu]>size[rootv]){
            size[rootu]+=size[rootv];
            parent[rootv] = rootu;
        }
        else{
            size[rootv]+=size[rootu];
            parent[rootu] = rootv;
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            ds.unionBySize(u, v);
        }
        unordered_map<int, int> cv;
        for(int i = 0; i<n; i++){
            int root = ds.find(i);
            cv[root]++; 
        }
        unordered_map<int, int> ce;
        int ans = 0;
        for(auto it: edges){
            int root = ds.find(it[0]);
            ce[root]++;
        }
        for(auto it: cv){
            int v = it.second;
            int node = it.first;
            int edges = ce[node];
            if(edges == v*(v-1)/2) ans++;
        }
        return ans;
    }
};