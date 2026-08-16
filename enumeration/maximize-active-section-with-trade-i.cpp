class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int cnt1 = count(s.begin(), s.end(), '1');
        vector<int> zero;
        int c =0;
        for (char ch : s) {
            if (ch == '0') {
                c++;
            } else {
                if (c > 0) zero.push_back(c);
                c = 0;
            }
        }
        if (c > 0) zero.push_back(c);
        cout<<"zerosiize:"<<zero.size()<<endl;
        int maxi=0;
        for(int i= 1; i<zero.size(); i++){
            maxi=max(zero[i-1]+zero[i],  maxi);
        }
        cout<<maxi<<endl;
        return maxi+cnt1;
    }
};