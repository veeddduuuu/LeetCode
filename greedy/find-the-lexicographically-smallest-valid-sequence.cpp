class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> v(m, 0);
        int matched = 0;
        bool flag = false;
        int i = m-1;
        int j = n-1;
        while(i>=0){
            if(j>=0 and word1[i] == word2[j]){
                matched++;
                j--;
            }
            v[i] = matched;
            i--;
        }

        vector<int> ans;
        i = 0;
        j = 0;
        while(i<m and j<n){
            if(word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!flag && i+1<m && v[i+1]>=n-j-1){
                ans.push_back(i);
                flag = true;
                j++;
            }
            i++;
        }

        return j==n ? ans : vector<int>();
    }
};