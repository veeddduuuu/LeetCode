#define ll long long
class Solution {
public:

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxi+1, 0);
        for(auto n: nums){
            for(int j= 1; j*j<= n; j++){
                if(n%j==0){
                    freq[j]++;
                    if(n/j!=j) freq[n/j]++;
                }
            }
        }

        vector<ll> count(maxi+1, 0);
        for(int i= maxi; i>= 1; i--){
            ll c = freq[i];
            count[i] = c*(c-1)/2;
            for(int j= i*2; j<=maxi; j+=i){
                count[i]-=count[j];
            }
        }   

        vector<ll> psum(maxi+1, 0);
        psum[0]= 0;
        for(int i= 1; i<=maxi; i++){
            psum[i]= psum[i-1]+count[i];
        }

        vector<int> ans;
        for(ll q: queries){
            int l = 1;
            int r= maxi;
            int temp= 1;
            while(l<=r){
                int mid= l+(r-l)/2;
                if(psum[mid]>q){
                    temp = mid;
                    r= mid-1;
                }else{
                    l=mid+1;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};