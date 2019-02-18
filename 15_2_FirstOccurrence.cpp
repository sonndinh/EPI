#include <iostream>
#include "common.h"

using namespace std;

// Find the first occurrence of k in a subtree rooted at a given node. 
const unique_ptr<BSTNode<int>>& find(const unique_ptr<BSTNode<int>>& node, int k) {
	if (node == nullptr) return nullptr;

	// Inorder traversal.
	auto& ln = find(node->left, k);
	if (ln) return ln;
	if (node->data == k) return node;
	auto& rn = find(node->right, k);
	if (rn) return rn;
	return nullptr;
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

	auto& ret = find(root, 40);
	cout << (ret? "Found!" : "Not Found!") << endl;
	return 0;
}
