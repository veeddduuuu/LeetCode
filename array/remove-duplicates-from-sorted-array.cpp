class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        vector <int> temp;
        temp.push_back(nums[0]);

        for (int i = 0; i<n-1; i++){
            if (nums[i]!=nums[i+1]){
                temp.push_back(nums[i+1]);
            }
        }

        nums = temp;
        return  temp.size();
        
    }
};