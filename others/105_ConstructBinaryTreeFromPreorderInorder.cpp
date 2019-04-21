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
    // Construct a subtree from the corresponding parts of preorder and inorder data.
    TreeNode* helper(vector<int>& preorder, int s1, int e1, vector<int>& inorder, int s2, int e2, unordered_map<int, int>& inorder_map) {
        if (s1 > e1) {
            return nullptr;
        }
        
        int val = preorder[s1];
        int inorder_idx = inorder_map[val];
        TreeNode *node = new TreeNode(val);
        int left_inorder_start = s2, left_inorder_end = inorder_idx - 1;
        int right_inorder_start = inorder_idx + 1, right_inorder_end = e2;
        int left_preorder_start = s1 + 1, left_preorder_end = s1 + 1 + (inorder_idx-1-s2);
        int right_preorder_start = left_preorder_end + 1, right_preorder_end = e1;
        
        node->left = helper(preorder, left_preorder_start, left_preorder_end, inorder, left_inorder_start, left_inorder_end, inorder_map);
        node->right = helper(preorder, right_preorder_start, right_preorder_end, inorder, right_inorder_start, right_inorder_end, inorder_map);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map from values to the corresponding indices in inorder data.
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }
        
        int size = preorder.size();
        return helper(preorder, 0, size-1, inorder, 0, size-1, inorder_map);
    }
};
