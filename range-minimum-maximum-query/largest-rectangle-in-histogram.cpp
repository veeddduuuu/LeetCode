class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> nse(n);
        vector<int> pse(n);
        stack<int> st;

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && h[st.top()]>=h[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = 0; i<n; i++){
            while(!st.empty() && h[st.top()]>=h[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        int maxarea = INT_MIN;
        
        for(int i = 0; i<n; i++){
            int area = h[i]*(nse[i] - pse[i] - 1);
            maxarea = max(area, maxarea);
        }

        return maxarea;

    }
};