class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int n = s.size(), m = g.size(), i = 0, j=0, ans=0;
        while(i<n && j<m){
            if(s[i]>=g[j]){
                j++;
            }
            i++;
        }
        return j;
    }
};