class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        
        int c1 = 0;
        int c2 = 0;

        for (int i = 0; i<n; i++){
            if (nums[i] == 0) {
                c2 = max(c1, c2);
                c1 = 0;
                continue;
            }
            c1++; 
        }

        return max(c1,c2);
    }
};