class Solution {
public:
    int n;
    // int func(int i, int j, vector<int> &nums){
    //     if(i > j) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int pick = nums[i]+func(i+2, j, nums);
    //     int notPick = func(i+1, j, nums);
    //     return dp[i] = max(pick, notPick);
    // }
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n == 1) return nums[0];
        int prev = nums[0];
        int prev2 = 0;
        for(int i = 1; i<n-1; i++){
            int pick = nums[i];
            if(i>1) pick+=prev2;
            int notPick = prev;
            int curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        int a = prev;
        prev = nums[1];
        prev2 = 0;
        for(int i = 2; i<n; i++){
            int pick = nums[i];
            if(i>2) pick+=prev2;
            int notPick = prev;
            int curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        int b = prev;
        return max(a, b);
        // dp.assign(n+1, -1);
        // int a = func(0, n-2, nums);
        // dp.assign(n+1, -1);
        // int b = func(1, n-1, nums);
        // return max(a, b);
    }
};