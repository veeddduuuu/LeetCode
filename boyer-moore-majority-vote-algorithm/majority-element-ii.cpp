class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans;
        unordered_map<int,int> mpp;

        for (auto i : nums){
            mpp[i]++;
        }

        for (auto i : mpp){
            if (i.second>n/3){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};