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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return  -1;
        int extra =  0;
        DisjointSet ds(n);
        for(auto edge : connections){
            int u = edge[0];
            int v  = edge[1];
            if(ds.find(u) == ds.find(v)){
                extra++;
            }
            else{
                ds.unionBySize(u, v);
            }
        }
        int comp =  0;
        for(int i = 0; i<n; i++){
            if(ds.find(i) == i) comp++; 
        }
        return extra>=(comp-1) ? comp-1 : -1;
    }
};