#include <iostream>
#include "common.h"

using namespace std;

// Each node contains a binary digit.
// @node: current node being traversed.
// @total: reference to the total sum of root-to-leaf paths computed so far.
// @curr: value for the root-to-leaf for the current path.
void helper(const unique_ptr<BinaryTreeNode<int>>& node, int& total, int curr) {
	if (node == nullptr)
		return;
	
	// Current value from the tree's root down to this node.
	curr = curr*2 + node->data;
	
	// If this is a leaf, update the total sum.
	if (node->left == nullptr && node->right == nullptr) {
		total += curr;
		return;
	}

	helper(node->left, total, curr);
	helper(node->right, total, curr);
}

int sum(const unique_ptr<BinaryTreeNode<int>>& root) {
	int total = 0;
	helper(root, total, 0);
	return total;
}

int main() {
	unique_ptr<BinaryTreeNode<int>> root(new struct BinaryTreeNode<int>);
	root->data = 1;

	// Nodes at level 1.
	root->left = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->left->data = 0;
	root->right = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->right->data = 1;

	// Nodes at level 2.
	root->left->left = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->left->left->data = 0;
	root->left->right = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->left->right->data = 1;
	root->right->left = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->right->left->data = 0;
	//	root->right->right = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	//	root->right->right->data = 0;

	cout << "Sum of root-to-leaf paths: " << sum(root) << endl;
	
	return 0;
}
