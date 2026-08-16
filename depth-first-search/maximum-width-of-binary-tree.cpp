/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left\nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        int maxwidth = 0;
        q.push({root, 0});

        while(!q.empty()){
            int size = q.size();
            long long stind = q.front().second;
            long long endind = q.back().second;
            maxwidth = max(maxwidth, (int)(endind-stind+1));
            for(int i = 0; i<size; i++){
                auto it = q.front();
                q.pop();
                TreeNode* node = it.first;
                long long k = it.second - stind;
                if(node->left) q.push({node->left, 2*k+1});
                if(node->right) q.push({node->right, 2*k+2});
            }
        }

        return maxwidth;
    }
};