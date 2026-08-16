class Solution {
public:
    int maxProfit(int cap, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(cap+1, 0));
        vector<vector<int>> curr(2, vector<int>(cap+1, 0));
        for(int i = n-1; i>=0; i--){
            for(int k = 1; k<=cap; k++){
                curr[1][k] = max(-prices[i]+after[0][k], after[1][k]);
                curr[0][k] = max(prices[i]+after[1][k-1], after[0][k]);
            }  
            after = curr;   
        }   
        return after[1][cap];
    }
};