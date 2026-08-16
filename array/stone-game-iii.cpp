class Solution {
public:
    int n;
    vector<int> dp;
    int f(int i, vector<int>& stoneValue){
        if(i>=n) return 0;
        if(dp[i] != INT_MIN) return dp[i];
        int one = stoneValue[i] - f(i+1, stoneValue);
        int two = INT_MIN;
        if(i+1<=n-1) two = stoneValue[i]+stoneValue[i+1] - f(i+2, stoneValue);
        int thre = INT_MIN;
        if(i+2<=n-1) thre = stoneValue[i]+stoneValue[i+1]+stoneValue[i+2] - f(i+3, stoneValue);
        return dp[i] = max(one, max(two, thre));
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.assign(n, INT_MIN);
        if(f(0, stoneValue) == 0) return "Tie";
        return f(0, stoneValue)>0 ? "Alice" : "Bob"; 
    }
};