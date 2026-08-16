class Solution {
public:
    int n;
    
    // int f(int i, int f1, int f2,vector<int>& prices){
    //     if(f2 == 0 || i == n) return 0;
    //     if(dp[i][f1][f2]!=-1) return dp[i][f1][f2];
    //     if(f1==1) return dp[i][f1][f2] = max(-prices[i]+f(i+1, 0, f2,prices), f(i+1, 1, f2,prices));
    //     else return dp[i][f1][f2] = max(prices[i]+f(i+1, 1, f2-1,prices), f(i+1, 0, f2,prices));
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       
        vector<vector<int>> after(2, vector<int>(3,0));
        vector<vector<int>> curr(2, vector<int>(3,0));
        
        for(int i=n-1;i>=0;i--){
            curr[0][0] = curr[1][0] = 0;
            for(int k = 1; k<=2; k++){
                curr[1][k] = max(-prices[i]+after[0][k], after[1][k]);
                curr[0][k] = max(prices[i]+after[1][k-1], after[0][k]); 
            }
            after = curr;
        }
        return after[1][2];
    }
};