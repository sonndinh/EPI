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
    TreeNode* dfs(TreeNode *node, TreeNode *a, unordered_set<TreeNode*>& path, unordered_set<TreeNode*>& visited ) {
        if (node == a) {
            path.insert(a);
            return a;
        }
        
        visited.insert(node);
        if (node->left && visited.count(node->left) == 0) {
            TreeNode *ret = dfs(node->left, a, path, visited);
            if (ret) {
                path.insert(node);
                return ret;
            }
        }
        if (node->right && visited.count(node->right) == 0) {
            TreeNode *ret = dfs(node->right, a, path, visited);
            if (ret) {
                path.insert(node);
                return ret;
            }
        }
        
        return nullptr;
    }
    
    // Return the LCA.
    TreeNode* lca(TreeNode *node, TreeNode *b, unordered_set<TreeNode*>& path_to_a, unordered_set<TreeNode*>& visited, bool& found) {
        if (node == b) {
            found = true;
            if (path_to_a.count(b) > 0) {
                // Node b is the LCA of both a and b.
                return b;
            }
            return nullptr;
        }
        
        if (node->left) {
            TreeNode *ret = lca(node->left, b, path_to_a, visited, found);
            if (ret) return ret;
            if (found && path_to_a.count(node) > 0) {
                return node;
            }
        }
        if (node->right) {
            TreeNode *ret = lca(node->right, b, path_to_a, visited, found);
            if (ret)  return ret;
            if (found && path_to_a.count(node) > 0) {
                return node;
            }
        }
        
        return nullptr;
    }
    
    TreeNode *lca(TreeNode *node, TreeNode *a, TreeNode *b) {
        if (node->val > a->val && node->val > b->val)
            return lca(node->left, a, b);
        else if (node->val < a->val && node->val < b->val)
            return lca(node->right, a, b);
        else
            return node;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *small = p->val < q->val ? p : q;
        TreeNode *large = p->val > q->val ? p : q;
        return lca(root, small, large);
    }
    
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;
        
        unordered_set<TreeNode*> visited, path_to_p;
        dfs(root, p, path_to_p, visited);
        visited.clear();
        bool found = false;
        return lca(root, q, path_to_p, visited, found);
    }
};
