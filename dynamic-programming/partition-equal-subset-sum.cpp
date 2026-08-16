class Solution {
public:
    int n;
    // int func(int i, int t, vector<int>& nums){
    //     if(t == 0) return 1;
    //     if(i >= n) return 0;
    //     if(curr[t]!=-1) return curr[t];
    //     int notPick = func(i+1, t, nums);
    //     int pick = 0;
    //     if(nums[i]<=t) pick = func(i+1, t-nums[i], nums);
    //     return curr[t] = pick|notPick;
    // }

    bool canPartition(vector<int>& nums) {
        int t = 0;
        for(auto i : nums) t+=i;
        if(t%2!=0) return false;
        t = t/2;
        n = nums.size();
        vector<int> curr(t+1, 0);
        vector<int> after(t+1, 0);
        for(int i = n-1; i>=0; i--){
            curr[0] = 1;
            for(int j = 1; j<=t; j++){
                int notPick = after[j];
                int pick = 0;
                if(nums[i]<=j) pick = after[j-nums[i]];
                curr[j] = pick | notPick;
            }
            after = curr;
        }
        return after[t];
    }
};