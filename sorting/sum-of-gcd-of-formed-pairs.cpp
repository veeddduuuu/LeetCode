class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi=INT_MIN;
        vector<int> v;
        for(int i = 0; i<n;i++){
            maxi = max(nums[i], maxi);
            v.push_back(gcd(maxi, nums[i]));
        }
        sort(v.begin(), v.end());
        int i=0, j=v.size()-1;
        long long ans=0;
        while(i<j){
            ans+=gcd(v[i], v[j]);
            i++;
            j--;
        }
        return ans;
    }
};