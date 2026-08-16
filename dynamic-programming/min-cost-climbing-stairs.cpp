class Solution {
public:
    int n;
    int func(int i, vector<int> &cost, vector<int> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(func(i+1, cost, dp), func(i+2, cost, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        vector<int> dp(n+1, -1);
        return min(func(0, cost, dp), func(1, cost, dp));
    }
};