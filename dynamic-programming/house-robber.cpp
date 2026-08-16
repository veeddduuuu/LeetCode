class Solution {
public:
    int func(int i, vector<int> &arr,  vector<int> &dp){
        if(i>=arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick = arr[i]+func(i+2, arr, dp);
        int notPick = func(i+1, arr, dp);
        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev = nums[0];
        for(int i = 1; i<nums.size(); i++){
            int pick=nums[i];
            if(i>1){
                pick += prev2;
            } 
            int notPick = prev;
            int curri = max(pick, notPick);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};