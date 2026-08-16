class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mpp[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            int sub = target - nums[i];
            if (mpp.count(sub) && mpp[sub] != i) {
                return {i, mpp[sub]};
            }
        }

        return {};
    }
};