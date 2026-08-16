class Solution {
private:
    void helper(int i, int n, int sum, vector<int> &v, vector<int> &temp, vector<vector<int>> &ans){
        if(sum == 0){
            ans.push_back(temp);
            return;
        }
        
        if(i==n || sum<0) return;

        temp.push_back(v[i]);
        helper(i+1, n, sum-v[i], v, temp, ans);
        temp.pop_back();
        
        int j = i+1;
        while(j<n && v[i] == v[j]){
            j++;
        }
        
        helper(j, n, sum, v, temp, ans);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        helper(0, candidates.size(), target, candidates, temp, ans);
        return ans;
    }
};