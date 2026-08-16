class Solution {
private:
    void helper(int i, int n, int sum, vector<int> &v, vector<int> &temp, vector<vector<int>> &ans ){
        if(sum == 0){
            ans.push_back(temp);
            return;
        }

        if(i>=n || sum<0) return;

        temp.push_back(v[i]);
        helper(i, n, sum-v[i], v, temp, ans);
        temp.pop_back();
        helper(i+1, n, sum, v, temp, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(0, candidates.size(), target, candidates, temp, ans);
        return ans;   
    }
};