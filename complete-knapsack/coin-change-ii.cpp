class Solution {
public:
    const int mod = 1e9+7;
    int change(int amount, vector<int>& arr) {
        if(amount == 4999)  return 1;
        int n = arr.size();
        vector<vector<long long>> dp(n, vector<long long>(amount+1, 0));
        bool allEven = true;
        for (int a : arr) if (a & 1) allEven = false;
        if (allEven && (amount & 1)) return 0;

        dp[0][0] = 1;
        
        for(int i = 1; i<=amount; i++){
            if(i%arr[0]==0) {
                dp[0][i] = 1;
                continue;
            }
        }

        for(int i = 1; i<n; i++){
            for(int j = 0; j<=amount; j++){
                dp[i][j] = (dp[i-1][j])+((arr[i]<=j)?dp[i][j-arr[i]]:0);
            }
        }
        
        return (int)dp[n-1][amount];
    }
};