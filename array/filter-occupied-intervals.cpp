class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        vector<vector<int>>  merged;
        // merged.push_back(occupiedIntervals[0]);
        for(auto it : occupiedIntervals){
            // auto last = merged.back();
            if(merged.empty()){
                merged.push_back(it);
                continue;
            }
            if(merged.back()[1]>=it[0]-1){
                merged.back()[1] = max(merged.back()[1], it[1]); 
            }
            else{
                merged.push_back(it);
            }
        }

        vector<vector<int>> final;

        for(auto it: merged){
            if(it[0]>freeEnd || it[1]<freeStart){
                final.push_back(it);
                continue;
            }
            if(it[0]<=freeStart-1) final.push_back({it[0], freeStart-1});
            if(it[1]>=freeEnd+1) final.push_back({freeEnd+1, it[1]});
        }
        return final;
    }
};