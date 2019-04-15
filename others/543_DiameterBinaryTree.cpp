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
    // Return the lengths of longest paths to a leaf on its 
    // left subtree and a leaf on its right subtree.
    pair<int, int> helper(TreeNode *node, int& max_length) {
        if (!node) {
            return {-1, -1};
        }
        
        pair<int, int> left = helper(node->left, max_length);
        pair<int, int> right = helper(node->right, max_length);
        
        int max_left = max(left.first, left.second);
        int max_right = max(right.first, right.second);
        if (max_length < max_left + 1 + max_right + 1) {
            max_length = max_left + 1 + max_right + 1;
        }
        
        return {max_left+1, max_right+1};
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max_length = 0;
        helper(root, max_length);
        return max_length;
    }
};
