/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mpp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i<size; i++){
                auto p = q.front();
                TreeNode* node = p.first;
                int row = p.second.first;
                int col = p.second.second;
                q.pop();
                mpp[col][row].insert(node->val);
                if(node->left){
                    q.push({node->left, {row+1, col-1}});
                }
                if(node->right){
                    q.push({node->right, {row+1, col+1}});
                }
            }
        }
        vector<vector<int>> ans;

        for(auto &col : mpp){
            vector<int> temp;
            for(auto &row : col.second){
                temp.insert(temp.end(), row.second.begin(), row.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};