class Solution {
private:
    void helper(int num, int sum, int k, vector<int> &temp, vector<vector<int>> &ans){
        if(sum == 0 && k==0){
            ans.push_back(temp);
            return;
        }

        if(sum<0 || k<0 || num>9){
            return;
        }

        temp.push_back(num);
        helper(num+1, sum-num, k-1, temp, ans);
        temp.pop_back();
        helper(num+1, sum, k, temp, ans);
    }
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(1, n, k, temp, ans);
        return ans;
    }
};