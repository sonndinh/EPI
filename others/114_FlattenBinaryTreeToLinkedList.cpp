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
    TreeNode* helper(TreeNode *node) {
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        
        TreeNode *left_end = nullptr;
        if (left) {
            left_end = helper(left);
            node->right = left;
            node->left = nullptr;
            left_end->right = right;
        }

        TreeNode *right_end = nullptr;
        if (right) {
            right_end = helper(right);
        }
        
        return right_end ? right_end : (left_end ? left_end : node);
    }
    
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        helper(root);
    }
};
