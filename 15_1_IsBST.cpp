#include <iostream>
#include "common.h"
using namespace std;

bool validate(const unique_ptr<BSTNode<int>>& node, int& min, int& max) {
	if (!node->left && !node->right) {
		// Subtree only contains a single node.
		min = node->data;
		max = node->data;
		return true;
	}
	
	// Validate the left subtree.
	int left_min = node->data, left_max = node->data;
	if (node->left) {
		if (!validate(node->left, left_min, left_max) || left_max >= node->data)
			return false;
	}

	// Validate the right subtree.
	int right_min = node->data, right_max = node->data;
	if (node->right) {
		if (!validate(node->right, right_min, right_max) || right_min <= node->data)
			return false;
	}

	// Update the min and max for the input subtree.
	min = left_min;
	max = right_max;
	return true;
}

// Traverse a subtree rooted at a given node.
// Return true if it is a binary search tree, false otherwise.
// WRONG ONE!
bool traverse(const unique_ptr<BSTNode<int>>& node) {
	if (node == nullptr) return true;

	if (traverse(node->left) == false || traverse(node->right) == false)
		return false;
	if (node->left != nullptr && node->data < node->left->data)
		return false;
	if (node->right != nullptr && node->data > node->right->data)
		return false;

	return true;
}

int main() {
	unique_ptr<BSTNode<int>> root(new BSTNode<int>);
	root->data = 314;
	root->left = unique_ptr<BSTNode<int>> (new BSTNode<int>);
	root->left->data = 67;
	root->right = unique_ptr<BSTNode<int>> (new BSTNode<int>);
	root->right->data = 350;
	root->left->left = unique_ptr<BSTNode<int>> (new BSTNode<int>);
	root->left->left->data = 60;
	root->left->right = unique_ptr<BSTNode<int>> (new BSTNode<int>);
	root->left->right->data = 80;
	root->right->left = unique_ptr<BSTNode<int>> (new BSTNode<int>);
	root->right->left->data = 200; //320;
	root->right->right = unique_ptr<BSTNode<int>> (new BSTNode<int>);
	root->right->right->data = 400;
	root->left->left->left = unique_ptr<BSTNode<int>> (new BSTNode<int>);
	root->left->left->left->data = 50;

	int min, max;
	cout << "Tree is " << (validate(root, min, max)? "a BST!" : "NOT a BST!") << endl;
	return 0;
}
