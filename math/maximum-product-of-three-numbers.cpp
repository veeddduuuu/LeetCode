class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       int n = nums.size();
        if(nums.size()<3) return 0;
        sort(nums.rbegin(), nums.rend());
        return max(nums[0]*nums[1]*nums[2], nums[n-1]*nums[n-2]*nums[0]);
        
    }
};