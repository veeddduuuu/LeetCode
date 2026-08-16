class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for(int i = 1; i<=9; i++){
            q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int n = q.front();
            q.pop();
            if(n>=low and n<=high) ans.push_back(n);
            int ld = n%10;
            if(ld == 9) continue;
            int nn = n*10+(ld+1);
            if(nn<=high) q.push(nn);
        }
        return ans;
    }
};