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
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        int min, max;
        return validate(root, min, max);
    }

private:
    bool validate(TreeNode *node, int& min, int& max) {
        if (!node->left && !node->right) {
            // Subtree only contains a single node.
            min = node->val;
            max = node->val;
            return true;
        }

        // Validate the left subtree.                     
        int left_min = node->val, left_max = node->val;
        if (node->left) {
            if (!validate(node->left, left_min, left_max) || left_max >= node->val)
                return false;
        }

        // Validate the right subtree.
        int right_min = node->val, right_max = node->val;
        if (node->right) {
            if (!validate(node->right, right_min, right_max) || right_min <= node->val)
                return false;
        }

        // Update the min and max for the input subtree.
        min = left_min;
        max = right_max;
        return true;
    }
};
