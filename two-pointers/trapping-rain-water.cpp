class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefixmax(n);
        vector<int> suffixmax(n);
        prefixmax[0] = height[0];
        suffixmax[n-1] = height[n-1];
        
        for(int i = 1; i<n; i++){
            prefixmax[i] = max(prefixmax[i-1], height[i]);
            suffixmax[n-i-1] = max(suffixmax[n-i], height[n-i-1]);
        }

        int ans = 0;
        
        for(int i = 0; i<n; i++){
            if(height[i]<prefixmax[i] && height[i]<suffixmax[i]){
                ans+=min(suffixmax[i], prefixmax[i]) - height[i];
            }
        }
        return ans;

    }
};


//height = 4 2 0 3 2 5
//prefix = 4 4 4 4 4 5
//suffix = 5 5 5 5 5 5
//2 + 4 + 1 + 2 