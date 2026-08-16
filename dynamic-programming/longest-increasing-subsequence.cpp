class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for(auto x : nums){
            auto it = lower_bound(v.begin(), v.end(), x);
                if(it == v.end()) v.push_back(x);
                else *it = x;
            }
        return v.size();
    }
};