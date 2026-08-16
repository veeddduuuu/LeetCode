class Solution {
private:
    void helper(int ind, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans){
        if(ind == nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        helper(ind+1, nums, temp, ans);
        temp.pop_back();
        for(int i = ind+1; i<nums.size(); i++){
            if(nums[i]!=nums[ind]){
                helper(i, nums, temp, ans);
                return;
            }
        }
        helper(nums.size(), nums, temp, ans);
    }
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        helper(0, nums, temp, ans);
        return ans;
    }
};