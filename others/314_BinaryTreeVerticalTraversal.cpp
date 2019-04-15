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
    // Visit nodes using pre-order traversal.
    void helper(vector<vector<int>>& ret, TreeNode *node, int offset, int min_offset) {
        ret[offset-min_offset].push_back(node->val);
        if (node->left) {
            helper(ret, node->left, offset-1, min_offset);
        }
        if (node->right) {
            helper(ret, node->right, offset+1, min_offset);
        }
    }
    
    void traverse(TreeNode *node, int offset, int& min_offset, int& max_offset) {
        if (min_offset > offset)
            min_offset = offset;
        if (max_offset < offset)
            max_offset = offset;
        
        if (node->left) {
            traverse(node->left, offset-1, min_offset, max_offset);
        }
        if (node->right) {
            traverse(node->right, offset+1, min_offset, max_offset);
        }
    }
    
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root)
            return ret;
        
        // Compute the max and min offsets.
        int min = 0, max = 0;
        traverse(root, 0, min, max);
        ret.resize(max - min + 1);
        
        // Traverse nodes in level order.
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            pair<TreeNode*, int>& p = q.front();
            ret[p.second - min].push_back(p.first->val);
            if (p.first->left)
                q.push({p.first->left, p.second-1});
            if (p.first->right)
                q.push({p.first->right, p.second+1});
            q.pop();
        }
        
        return ret;
    }
};
