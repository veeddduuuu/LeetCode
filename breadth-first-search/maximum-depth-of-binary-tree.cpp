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
    void helper(TreeNode* root, int x, int &y){
        if(root == NULL) {
            y = max(x, y);
            x--;
            return;
        }
        helper(root->left, x+1, y);
        helper(root->right, x+1, y);
    }
    int maxDepth(TreeNode* root) {
        int depth = 0;
        int maxdepth = 0;
        helper(root, depth, maxdepth);
        return maxdepth;
    }
};