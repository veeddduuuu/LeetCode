/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) s.append("#,");
            else{
                s.append(to_string(node->val)+",");
                q.push(node->left);
                q.push(node->right);
            }
       }
       return s; 
    }

    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        if(str == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            getline(s, str, ',');
            if(str.empty() || str == "#") node->left = NULL;
            else{
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            getline(s, str, ',');
            if(str.empty() || str == "#") node->right = NULL;
            else{
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;

    }
};