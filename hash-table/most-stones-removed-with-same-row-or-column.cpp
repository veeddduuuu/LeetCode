class DisjointSet {
    public:
    vector<int> size, parent;

    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }
    int find(int node){
        if(parent[node] == node)  return  node;
        return parent[node] = find(parent[node]);
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
    int removeStones(vector<vector<int>>& stones) {
        int n = 0;
        int m = 0;
        for(auto it  : stones){
            n =  max(n, it[0]);
            m =  max(m, it[1]);
        }
        DisjointSet ds(n+m+1);
        unordered_map<int, int> mpp;
        for(auto it : stones){
            int r = it[0];
            int c = it[1];
            ds.unionBySize(r, n+c+1);
            mpp[r] = 1;
            mpp[n+c+1] = 1;
        }

        int comp = 0;
        for(auto it : mpp){
            if(ds.find(it.first) == it.first) comp++;
        }
        return stones.size()-comp;
    }
};