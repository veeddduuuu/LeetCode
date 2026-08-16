class Solution {
public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<int> after(2, 0);
        vector<int> curr(2, 0);

        for(int i = n-1; i>=0; i--){
            curr[1] = max(-prices[i]+after[0], after[1]);
            curr[0] = max(prices[i]-k+after[1], after[0]);
            after = curr;
        }       
        return after[1];
    }
};