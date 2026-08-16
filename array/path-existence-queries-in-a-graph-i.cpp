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
    
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        DisjointSet ds(n);
        for(int i = 0; i<n-1; i++){
            if(nums[i+1]-nums[i]<=maxDiff){
                ds.unionBySize(i, i+1);
            }
        }

        vector<bool> res;
        for(auto q : queries){
            int u = q[0];
            int v = q[1];
            if(ds.find(u) == ds.find(v)) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};