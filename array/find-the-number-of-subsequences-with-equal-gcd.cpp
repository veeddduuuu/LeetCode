#define mod 1000000007
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    // int f(int i, int s1, int s2, vector<int>& nums){
    //     if (i == n) {
    //         return (s1 != 0 && s2 != 0 && s1 == s2);
    //     }
    //     long long ans = 0;
    //     if(dp[i][s1][s2]!=-1) return dp[i][s1][s2];
    //     ans+= f(i+1, gcd(nums[i], s1), s2, nums);
    //     ans+= f(i+1, s1, gcd(nums[i], s2), nums);
    //     ans+= f(i+1, s1, s2, nums);
    //     return dp[i][s1][s2] = ans%mod;
    // }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        int maxv = -1e8;
        for(auto x : nums){
            maxv = max(maxv, x);
        }
        
        vector<vector<int>> next(maxv+1, vector<int>(maxv+1, 0));
        vector<vector<int>> curr(maxv+1, vector<int>(maxv+1,  0));

        for(int j = 0; j<=maxv; j++){
            for(int k = 0; k<=maxv; k++){
                next[j][k] = (j != 0 && k != 0 && j == k);
            }
        }

        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<=maxv; j++){
                for(int k = 0; k<=maxv; k++){
                    long long ans = 0;
                    ans+= next[gcd(nums[i], j)][k];
                    ans+= next[j][gcd(nums[i], k)];
                    ans+= next[j][k];
                    curr[j][k] = ans%mod;
                }
            }
            next = curr;
        }

        return next[0][0];
    }
};