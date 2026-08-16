class Solution {
public:
    bool func(int k, int i, vector<int> &stones, vector<vector<int>> &dp){
        if(k == 0) return false;
        if(i == stones.size()-1) return true;
        if(dp[i][k]!=-1) return dp[i][k] == 1 ? true : false; 
        for(int j = i+1; j<stones.size(); j++){
            if(stones[i]+k == stones[j]){
                bool ans = func(k+1, j, stones, dp)||func(k, j, stones, dp)||func(k-1, j, stones, dp);
                dp[i][k] = (ans == true ? 1 : false);
            } 
        }
        if(dp[i][k] == 1) return true;
        else return false;
    }

    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0] != 1) return false;
        vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), -1));
        return func(1, 0, stones, dp);    
    }
};