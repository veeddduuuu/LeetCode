class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int count = 0;
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i; j<nums.size(); j++){
                if(nums[j] == target) count++;
                else count--;
                if(count>0) ans++;
            }
            count = 0;
        }
        return ans;
    }
};