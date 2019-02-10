#include <iostream>
#include <algorithm>
#include "common.h"

using namespace std;

// Return whether a subtree rooted at the given node is balanced, 
// and the height of the node.
bool helper(const unique_ptr<BinaryTreeNode<int>>& root, int& height) {
	int l_height, r_height; // Heights of left and right subtrees.
	bool l_balanced, r_balanced; // Whether the left and right subtrees are balanced.

	if (root->left != nullptr) {
		l_balanced = helper(root->left, l_height);
		l_height++; // Height of the root via left subtree.
	} else {
		l_balanced = true;
		l_height = 0;
	}
	if (!l_balanced) return false;

	if (root->right != nullptr) {
		r_balanced = helper(root->right, r_height);
		r_height++; // Height of root via right subtree.
	} else {
		r_balanced = true;
		r_height = 0;
	}
	if (!r_balanced) return false;
	
	// Height of the root.
	height = max(l_height, r_height);

	// Else, check their heights.
	return (l_height <= r_height ? r_height - l_height <= 1 : l_height - r_height <= 1);
}

// Return whether a binary tree is balanced.
bool is_balanced(const unique_ptr<BinaryTreeNode<int>>& root) {
	int height;
	return helper(root, height);
}

int main() {
	unique_ptr<BinaryTreeNode<int>> root(new struct BinaryTreeNode<int>);
	root->data = 314;
	root->left = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->left->data = 67;
	root->right = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->right->data = 76;
	root->left->left = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->left->left->data = 271;
	root->left->right = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->left->right->data = 561;
	//	root->right->left = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	//	root->right->left->data = 5;
	//	root->right->right = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	//	root->right->right->data = 89;
	root->left->left->left = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->left->left->left->data = 500;

	cout << "Tree is" << (is_balanced(root)? " Balanced!" : " Imbalanced!") << endl;

	return 0;
}
