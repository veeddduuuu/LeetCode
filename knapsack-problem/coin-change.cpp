class Solution {
public:
    vector<vector<int>> dp;
    // int f(int i, int t, vector<int>& arr){
        
    //     if(t<0) return 1e9;
    //     if(t==0) return dp[i][t] = 0;
    //     if(i<0) return 1e9;
    //     // if(t>0 and i==0){
    //     //     if(t%arr[0]==0) return dp[i][t] = t/arr[0];
    //     //     else return dp[i][t] = 1e9;
    //     // }
    //     if(dp[i][t]!=-1 ) return dp[i][t];
    //     int notPick = f(i-1, t, arr);
    //     int pick = 1e9;
    //     if(arr[i]<=t) pick = 1+f(i,  t-arr[i], arr);
    //     return dp[i][t] = min(pick, notPick);

    // }

    const int INF = 1e9;

    int coinChange(vector<int>& arr, int amount) {
        int n  = arr.size();
        dp.assign(n, vector<int>(amount+1, 0));

        for(int i = 0; i<=amount; i++){
            dp[0][i] = (i%arr[0]==0) ? i/arr[0] : INF;
        }
 
        for(int i = 1; i<n; i++){
            for(int t = 0; t<=amount; t++){
                int notPick = dp[i-1][t];
                int pick = INF;
                if(arr[i]<=t) pick = 1+dp[i][t-arr[i]];
                dp[i][t] = min(pick , notPick);
            }
        }

        int ans = dp[n-1][amount];
        return ans==1e9 ? -1 : ans;
    }
};