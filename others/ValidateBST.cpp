#include <iostream>
#include <limits>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Return min and max of a subtree rooted at a given node.
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

// Determine if a binary tree is BST.
// All nodes on the left subtree must be smaller than the node's key.
// All nodes on the right subtree must be larger than the node's key.
bool isValidBST(TreeNode* root) {
	// Assuming an empty tree is a valid BST.
	if (!root) return true;
	int min, max;
	return validate(root, min, max);
}

int main() {
	TreeNode *root1 = new TreeNode(2);
	TreeNode *a1 = new TreeNode(1);
	TreeNode *a2 = new TreeNode(4);
	root1->left = a1;
	root1->right = a2;

	TreeNode *root2 = new TreeNode(10);
	TreeNode *b1 = new TreeNode(5);
	TreeNode *b2 = new TreeNode(15);
	TreeNode *b3 = new TreeNode(6);
	TreeNode *b4 = new TreeNode(20);
	root2->left = b1;
	root2->right = b2;
	b2->left = b3;
	b2->right = b4;

	cout << "Tree with root " << root1->val << (isValidBST(root1)? " is a BST" : " is NOT a BST") << endl;
	cout << "Tree with root " << root2->val << (isValidBST(root2)? " is a BST" : " is NOT a BST") << endl;
	return 0;
}
