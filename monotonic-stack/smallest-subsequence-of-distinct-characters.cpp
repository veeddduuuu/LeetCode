class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++)
            last[s[i]-'a'] = i;

        //c b a c d c b c
        //last = [a b c d ....]
        //last = [2 6 7 4]
        //stack = [F F F F ...]
        //string = "cb"
        vector<bool> stack(26, false);
        string ans="";

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (stack[ch-'a']) continue;

            while(!ans.empty() and ch<ans.back() and last[ans.back()-'a']>i) {
                stack[ans.back()-'a'] = false;
                ans.pop_back();
            }

            ans+=ch;
            stack[ch-'a'] = true;
        }

        return ans;
    }
};