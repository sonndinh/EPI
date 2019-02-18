#include <iostream>
#include "common.h"

using namespace std;

// Traverse a subtree rooted at a given node.
// Return true if it is a binary search tree, false otherwise.
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
	unique_ptr<BSTNode<int>> root(new struct BSTNode<int>);
	root->data = 314;
	root->left = unique_ptr<BSTNode<int>> (new struct BSTNode<int>);
	root->left->data = 67;
	root->right = unique_ptr<BSTNode<int>> (new struct BSTNode<int>);
	root->right->data = 350;
	root->left->left = unique_ptr<BSTNode<int>> (new struct BSTNode<int>);
	root->left->left->data = 60;
	root->left->right = unique_ptr<BSTNode<int>> (new struct BSTNode<int>);
	root->left->right->data = 80;
	root->right->left = unique_ptr<BSTNode<int>> (new struct BSTNode<int>);
	root->right->left->data = 320;
	root->right->right = unique_ptr<BSTNode<int>> (new struct BSTNode<int>);
	root->right->right->data = 400;
	root->left->left->left = unique_ptr<BSTNode<int>> (new struct BSTNode<int>);
	root->left->left->left->data = 50;

	cout << "Tree is " << (traverse(root)? "a Binary Search Tree!" : "not a Binary Search Tree!") << endl;
	return 0;
}
