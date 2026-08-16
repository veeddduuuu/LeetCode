class Solution {
public:
    int findNumberOfLIS(vector<int> arr) {
        int n = arr.size();
        if (n==1) return 1;
        vector<int> dp(n, 1);
        int lis = 0;
        vector<int> cnt(n, 1);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(arr[i]>arr[j]){
                    if(dp[i]<dp[j]+1){
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[i] == dp[j]+1){
                        cnt[i]+=cnt[j];
                    }
                }
                lis = max(lis, dp[i]);
            }
        }
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(dp[i] == lis)
                ans += cnt[i];
        }

        return ans;
    }
};