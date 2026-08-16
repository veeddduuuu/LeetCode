class Solution {
private:
    void nextsmallerelement(vector<int> &arr, vector<int> &nse){
        stack<int> st;
        int n = arr.size();
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) nse[i] = n;
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }
    }

    void previoussmallerequalelement(vector<int> &arr, vector<int> &psee){
        stack<int> st;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()) psee[i] = -1;
            else psee[i] = st.top();

            st.push(i);
        }

    }

public:
    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> nse(n);
        nextsmallerelement(arr, nse);
        vector<int> psee(n);
        previoussmallerequalelement(arr, psee);
        int mod = 1e9+7;
        int sum = 0;
        
        for(int i  = 0; i<n; i++){
            int x = nse[i]-i;
            int y = i-psee[i];
            long long f = x*y*1LL;
            int val = (f*arr[i]*1LL)%mod;
            sum=(sum+val)%mod;
        }
        return sum;
    }
};
