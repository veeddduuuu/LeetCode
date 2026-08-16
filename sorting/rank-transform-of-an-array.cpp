class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> mpp;
        int rank = 1;
        vector<int> v = arr;
        sort(v.begin(), v.end());
        for(auto i : v){
            if(mpp.find(i)==mpp.end()){
                mpp[i] = rank;
                rank++;
            }
        }
        for(int i = 0; i<arr.size(); i++){
            arr[i] = mpp[arr[i]];
        }
        return arr;
    }
};