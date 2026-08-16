class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map <int, int> hashOcount;
        unordered_map <int, int> hashOfreq;
        for (int i : arr){
            hashOcount[i]++;
        }
    
        for (const auto & f : hashOcount){
            int x = f.second;
            if (hashOfreq[x]>0){
                return false;
            }
            hashOfreq[x]++;
        }

        return true;
    }
};