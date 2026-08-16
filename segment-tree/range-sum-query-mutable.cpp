class NumArray {
    vector<int> tree;
    int n;
public:
    void build(vector<int>& nums, int i, int l, int r){
        if(l == r){
            tree[i] = nums[l];
            return;
        }
        int mid = l+(r-l)/2;
        build(nums, 2*i+1, l, mid);
        build(nums, 2*i+2, mid+1, r);
        tree[i] = tree[2*i+1] + tree[2*i+2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4*n, 0);
        build(nums, 0, 0, n-1);
    }
    
    void update(int index, int val) {
        return update(0, 0, n-1, index, val);
    }
    
    void update(int i, int l, int r, int idx, int val){
        if(l == r){
            tree[i] = val;
            return;
        }
        int mid = l+(r-l)/2;
        if(idx<=mid){
            update(2*i+1, l, mid, idx, val);
        }
        else{
            update(2*i+2, mid+1, r, idx, val);
        }
        tree[i] = tree[2*i+1]+tree[2*i+2];
    }

    int sumRange(int left, int right) {
        return query(0, 0, n-1, left, right);
    }

    int query(int i, int l, int r, int ql, int qr){
        if(r<ql or l>qr) return 0;
        if(ql<=l and qr>=r){
            return tree[i];
        }
        int mid = l+(r-l)/2;
        return query(2*i+1, l, mid, ql, qr) + query(2*i+2, mid+1, r, ql, qr);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */