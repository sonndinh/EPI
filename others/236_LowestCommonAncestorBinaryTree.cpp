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
    TreeNode* traverse_helper(TreeNode *curr, TreeNode *a, TreeNode *b, int& num) {
        int num_left = 0, num_right = 0;
        if (curr->left) {
            TreeNode *left = traverse_helper(curr->left, a, b, num_left);
            if (num_left == 2) {
                num = 2;
                return left;
            }
        }
        
        if (curr->right) {
            TreeNode *right = traverse_helper(curr->right, a, b, num_right);
            if (num_right == 2) {
                num = 2;
                return right;
            }
        }
        
        if (curr == a || curr == b)
            num = num_left + num_right + 1;
        else 
            num = num_left + num_right;
        return num == 2 ? curr : nullptr;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        int num_nodes = 0;
        return traverse_helper(root, p, q, num_nodes);
    }
};
