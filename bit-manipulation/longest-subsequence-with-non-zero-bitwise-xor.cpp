class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int t = 0;
        int n = nums.size();
        bool flag = false;
        for(int i : nums){
            if(i>0) flag = true;
            t^=i;
        }

        if(t!=0) return n;
        if(flag) return n-1;
        return 0;
    }
};