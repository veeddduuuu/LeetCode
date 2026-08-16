class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> st(nums.begin(), nums.end());
        int maxi = ranges::max(nums);
        int mini = ranges::min(nums);

        for(int i = mini+1; i<=maxi; i++){
            if(!st.contains(i)) ans.push_back(i);
        }

        return ans;
    }
};