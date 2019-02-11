#include <iostream>
#include "common.h"

using namespace std;

// Return true if the subtrees rooted at a left node and right node mirror each other.
bool helper(const unique_ptr<BinaryTreeNode<int>>& left, const unique_ptr<BinaryTreeNode<int>>& right) {
	if ((left == nullptr && right != nullptr) || (left != nullptr && right == nullptr)) return false;
	if (left == nullptr && right == nullptr) return true;
	if (left->data != right->data) return false;
	
	return helper(left->left, right->right) && helper(left->right, right->left);
}

// Check if a binary tree is symmetric.
bool is_symmetric(const unique_ptr<BinaryTreeNode<int>>& root) {
	return helper(root, root);
}

int main() {
	unique_ptr<BinaryTreeNode<int>> root(new struct BinaryTreeNode<int>);
	root->data = 314;
	root->left = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->left->data = 6;
	root->right = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->right->data = 6;
	
	root->left->right = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->left->right->data = 2;
	root->right->left = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->right->left->data = 2;

	root->left->right->right = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->left->right->right->data = 3;
	root->right->left->left = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->right->left->left->data = 3;

	cout << "Tree is " << (helper(root, root)? "Symmetric!" : "Asymmetric!") << endl;
	
	return 0;
}
