/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    pair<Node*, Node*> helper(Node *node) {
        pair<Node*, Node*> left_pair{nullptr, nullptr}, right_pair{nullptr, nullptr};
        if (node->left) {
            left_pair = helper(node->left);
        }
        if (node->right) {
            right_pair = helper(node->right);
        }
        node->left = left_pair.second;
        if (left_pair.second)
            left_pair.second->right = node;
        
        node->right = right_pair.first;
        if (right_pair.first)
            right_pair.first->left = node;
        
        return {left_pair.first? left_pair.first : node, right_pair.second? right_pair.second : node};
    }
    
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        
        pair<Node*, Node*> tmp = helper(root);
        tmp.first->left = tmp.second;
        tmp.second->right = tmp.first;
        return tmp.first;
    }
};
