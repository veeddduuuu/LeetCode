
class Solution {
public:
    typedef long long ll;
    long long maximumSumOfHeights(vector<int>& heights) {
        ll n = heights.size();
        ll ans = 0;
        for(ll i = 0; i<n; i++){
            ll sum = heights[i];
            int prev = heights[i];
            for(int j = i-1; j>=0; j--){
                prev = min(heights[j], prev);
                sum+=prev;
            }
            prev = heights[i];
            for(int j = i+1; j<n; j++){
                prev = min(heights[j], prev);
                sum+=prev;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};