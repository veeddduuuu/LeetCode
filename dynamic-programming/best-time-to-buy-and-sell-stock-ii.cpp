class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int func(int i, int f, vector<int> &arr){
        if(i == n){
            return 0; 
        }
        if(dp[i][f]!=-1) return dp[i][f];
        int pick = 0;
        int notPick = 0;
        if(f == 1){
            pick += -arr[i]+func(i+1, 0, arr);
            notPick += func(i+1, 1, arr);
        }
        else{
            pick += arr[i]+func(i+1, 1, arr);
            notPick += func(i+1, 0, arr);
        }
        return dp[i][f] = max(pick, notPick); 
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        // dp.assign(n+1, vector<int>(2, 0));
        // dp[n][0] = dp[n][1] = 0;
        int prevBuy = 0, prevSell = 0;
        for(int i = n-1; i>=0; i--){
            int currBuy = max(-prices[i]+prevSell, prevBuy);
            int currSell = max(prices[i]+prevBuy, prevSell);
            prevBuy = currBuy;
            prevSell = currSell;
        }
        return prevBuy;
    }
};