class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int m = n/2;
        sort(s.begin(), s.begin()+m);
        for(int i = 0; i<=m;i++){
            s[n-1-i]=s[i];
        }
        return s;
         
    }
};