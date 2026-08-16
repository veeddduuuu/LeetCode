#define ll long long
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(), nums.rend());
        ll sum = 0;
        for(int i = 0; i<k; i++){
            if(mul>0){
                sum+= 1ll*nums[i]*mul;
                mul--;
            }
            else{
                sum+=nums[i];
            }
        }
        return sum;
    }
};