class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        int lis = 1;
        int lisidx = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i]%nums[j] == 0 or nums[j]%nums[i] == 0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        parent[i] = j;
                        if(lis<dp[i]){
                            lis = dp[i];
                            lisidx = i;
                        }
                    }
                }
            }
        }
        vector<int> result;
        while(lisidx!=-1){
            result.push_back(nums[lisidx]);
            lisidx = parent[lisidx];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};