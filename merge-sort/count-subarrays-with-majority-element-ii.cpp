class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int cumSum = 0;
        mpp[cumSum] = 1;
        long long x = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                x += mpp[cumSum];
                cumSum+=1; 
            }
            else{
                cumSum-=1;
                x-=mpp[cumSum];
            }
            mpp[cumSum]+=1;
            ans+=x;
        }
        return ans;
    }
};