#include <iostream>
#include "common.h"

using namespace std;

// Find the first occurrence of k in a subtree rooted at a given node.
// Complexity: O(n).
BSTNode<int>* find(const unique_ptr<BSTNode<int>>& node, int k) {
	if (node == nullptr) return nullptr;

	// Inorder traversal.
	struct BSTNode<int> *ln = find(node->left, k);
	if (ln) return ln;
	if (node->data == k) return node.get();
	struct BSTNode<int> *rn = find(node->right, k);
	if (rn) return rn;
	return nullptr;
}

// Complexity O(h).
BSTNode<int>* find2(const unique_ptr<BSTNode<int>>& node, int k) {
	if (node == nullptr) return nullptr;

	if (node->data == k) {
		struct BSTNode<int> *ln = find(node->left, k);
		// Return the node from the left subtree if found one.
		if (ln != nullptr)
			return ln;
		// Otherwise, this is the node we need.
		return node.get();
	} else if (node->data > k) {
		return find(node->left, k);
	} else {
		return find(node->right, k);
	}
}

// Iterative implementation has better space complexity.
BSTNode<int>* find3(const unique_ptr<BSTNode<int>>& node, int k) {
	BSTNode<int> *curr = node.get();
	BSTNode<int> *first = nullptr;
	while (curr != nullptr) {
		if (curr->data == k) {
			first = curr;
			curr = (curr->left).get();
		} else if (curr->data > k) {
			curr = (curr->left).get();
		} else {
			curr = (curr->right).get();
		}
	}
	return first;
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

	BSTNode<int> *ret = find3(root, 81);
	cout << (ret? "Found!" : "Not Found!") << endl;
	return 0;
}
