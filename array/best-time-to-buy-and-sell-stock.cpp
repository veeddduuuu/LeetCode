class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<int> arr(n, 1e9);
        
        // arr[0] = prices[0];
        // for(int i = 1; i<n; i++){
        //     arr[i] = min(arr[i-1], prices[i]);
        // }
        // for(auto i : arr){
        //     cout<<arr[i]<<" ";
        // }
        int ans = 0;
        int minn = 1e9;
        for(int i = 1; i<n; i++){
            minn = min(minn, prices[i-1]);
            ans = max(ans,prices[i]-minn);
        }
        return ans;

    }
};