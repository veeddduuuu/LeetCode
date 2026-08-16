class Solution {
private:
    void getNSE(vector<int>& nums, vector<int>& nse) {
        int n = nums.size();
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    void getPSE(vector<int>& nums, vector<int>& pse) {
        int n = nums.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    void getNGE(vector<int>& nums, vector<int>& nge) {
        int n = nums.size();
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    void getPGE(vector<int>& nums, vector<int>& pge) {
        int n = nums.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n), pse(n), nge(n), pge(n);

        getNSE(nums, nse);
        getPSE(nums, pse);
        getNGE(nums, nge);
        getPGE(nums, pge);

        long long minSum = 0, maxSum = 0;

        for (int i = 0; i < n; i++) {
            long long minCount = (i - pse[i]) * (nse[i] - i) * 1LL; 
            long long maxCount = (i - pge[i]) * (nge[i] - i) * 1LL; 
            minSum += minCount * nums[i] * 1LL; 
            maxSum += maxCount * nums[i] * 1LL;
        }

        return maxSum - minSum;
    }
};
