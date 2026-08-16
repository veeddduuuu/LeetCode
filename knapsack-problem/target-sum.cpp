class Solution {
public:
    int s = 0;
    vector<vector<int>> dp;
    int f(int i, int t, vector<int>& nums) {
        if (i == 0) {
            if (t == 0 && nums[0] == 0)
                return 2;
            if (t == 0 || t == nums[0])
                return 1;
            return 0;
        }
        if (dp[i][t] != -1)
            return dp[i][t];
        int pick = 0;
        if(t>=nums[i]) pick = f(i - 1, t - nums[i], nums);
        int notPick = f(i - 1, t, nums);
        return dp[i][t] = pick + notPick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        for (auto n : nums) {
            s += n;
        }
        if (abs(target) > s) return 0;
        if ((s + target) % 2) return 0;
        int t = (s + target) / 2;
        dp.assign(nums.size(), vector<int>(t + 1, -1));
        return f(nums.size() - 1, t, nums);
    }
};