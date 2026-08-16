class Solution {
public:
    struct Node{
        int pre = 0;
        int suff = 0;
        int maxlen = 0;
        char leftchar = 0;
        char rightchar = 0;
    };

    vector<Node> tree;
    int n;  

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n = s.size();
        tree.assign(4*n, Node());
        build(0, 0, n-1, s);
        vector<int> result;
        for(int i = 0; i<queryIndices.size(); i++){
            int idx = queryIndices[i];
            char val = queryCharacters[i];
            update(0, 0, n-1, idx, val);
            result.push_back(tree[0].maxlen);
        }
        return result;
    }

    void build(int i, int l, int r, const string &s){
        if(l == r){
            tree[i] = {1, 1, 1, s[l], s[l]};
            return;
        }
        int mid = l+(r-l)/2;
        build(2*i+1, l, mid, s);
        build(2*i+2, mid+1, r, s);
        tree[i] = merge(tree[2*i+1], tree[2*i+2], mid-l+1, r-mid);
    }

    Node merge(const Node &l, const Node &r, int leftlen, int rightlen){
        Node res;
        res.leftchar = l.leftchar;
        res.rightchar = r.rightchar;

        res.pre = l.pre;
        if(l.pre == leftlen and l.rightchar == r.leftchar){
            res.pre = l.pre+r.pre;
        }
        
        res.suff = r.suff;
        if(r.suff == rightlen and r.leftchar == l.rightchar){
            res.suff = l.suff + r.suff;
        } 

        res.maxlen = max(l.maxlen, r.maxlen);
        if(l.rightchar == r.leftchar){
            res.maxlen = max(res.maxlen, r.pre+l.suff);
        }

        return res;
    }

    void update(int i, int l, int r, int idx, char val){
        if(l == r){ 
            tree[i] = {1, 1, 1, val, val};
            return;
        }
        int mid = l+(r-l)/2;
        if(idx<=mid) update(2*i+1, l, mid, idx, val);
        else update(2*i+2, mid+1, r, idx, val);
        tree[i] = merge(tree[2*i+1], tree[2*i+2], mid-l+1, r-mid);

    }
};