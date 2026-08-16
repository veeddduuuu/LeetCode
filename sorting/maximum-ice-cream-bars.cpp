class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int maxel = *max_element(costs.begin(), costs.end());
        vector<int> freq(maxel+1);
        for(int cost : costs){
            freq[cost]++;
        }
        int ans = 0;
        for(int i = 1; i<=maxel; i++){
            if(freq[i] > 0){
                int x = min(freq[i], coins/i);
                coins-=i*x;
                ans+=x;
                if(coins==0) break;
            }
        }
        return ans;
            
    }
};