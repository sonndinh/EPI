/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void helper(vector<string>& ret, string path, TreeNode *root, TreeNode *node) {
        if (node == root) {
            path += to_string(node->val);
        } else {
            path += "->" + to_string(node->val);
        }
        
        if (!node->left && !node->right) {
            // Reach a leaf node.
            ret.emplace_back(path);
            return;
        }
        
        if (node->left)
            helper(ret, path, root, node->left);
        if (node->right)
            helper(ret, path, root, node->right);
    }
        
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (!root)
            return ret;
        
        helper(ret, "", root, root);
        return ret;
    }
};
