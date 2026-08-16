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
    bool isValid(int  r, int c, int n){
        return (r>=0 &&  r<n  && c>=0 && c<n);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int  n  = grid.size();
        DisjointSet ds(n*n);
        vector<int> dr = {0, 0, -1, 1};
        vector<int> dc = {1, -1, 0, 0};
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0)  continue;
                
                for(int k = 0;  k<4; k++){
                    int nr = i+dr[k];
                    int nc = j+dc[k];
                    if(isValid(nr, nc,  n)  && grid[nr][nc]==1){
                        ds.unionBySize(n*nr+nc, n*i+j);
                        //cell  no =  no of coloums*current row + no fo currnet coloum 
                    }
                }
            }
        }
        
        int ans = INT_MIN;
        for(auto s : ds.size){
            ans = max(ans, s);
        }
        
        
        

        for(int i  =  0; i<n; i++){
            for(int j = 0;  j<n; j++){
                if(grid[i][j] ==  0){
                    unordered_set<int> st;
                    
                    for(int k = 0;  k<4; k++){
                        int nr = i+dr[k];
                        int nc = j+dc[k];
                        if(isValid(nr, nc, n)  && grid[nr][nc]==1){
                            int node = n*nr+nc;
                            st.insert(ds.find(node));
                        }
                    }
                    int temp = 1;
                    for(auto node : st){
                        temp+=ds.size[node];
                    }
                    ans = max(ans, temp);
                }
            }
        }
        return ans;

    }
};