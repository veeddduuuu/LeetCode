class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int x = 0;
        int ans = 0;
        for(auto g : gain){
            x+=g;
            ans = max(x, ans);
        }
        return ans;
    }
};