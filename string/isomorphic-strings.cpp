class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char, char > mapS, mapT;

        for (int i = 0; i<s.length(); i++){
            
            if(mapS[s[i]]!=0 || mapT[t[i]]!=0) {
                if(mapS[s[i]] != t[i] || mapT[t[i]] != s[i]) return false;
            }

            mapS[s[i]] = t[i];
            mapT[t[i]] = s[i];
        }
        return true;
    }
};