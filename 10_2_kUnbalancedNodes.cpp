#include <iostream>
#include <cstdlib>
#include "common.h"

using namespace std;

// Return the node if the subtree rooted at this node is unbalanced, null otherwise.
struct BinaryTreeNode<int>* k_unbalanced(const unique_ptr<BinaryTreeNode<int>>& root, int& num_nodes, int k) {
	if (!root) {
		num_nodes = 0;
		return nullptr;
	}

	int left_nodes, right_nodes;
	struct BinaryTreeNode<int> *l_unbalanced = k_unbalanced(root->left, left_nodes, k);
	if (l_unbalanced) return l_unbalanced;
	
	BinaryTreeNode<int> *r_unbalanced = k_unbalanced(root->right, right_nodes, k);
	if (r_unbalanced) return r_unbalanced;

	if (abs(left_nodes - right_nodes) > k) return root.get();
	
	num_nodes = left_nodes + right_nodes + 1;
	return nullptr;
}

struct BinaryTreeNode<int>* find(const unique_ptr<BinaryTreeNode<int>>& root, int k) {
	if (!root)
		return nullptr;

	int total_nodes;
	struct BinaryTreeNode<int> *node = k_unbalanced(root, total_nodes, k);
	return node;
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
	root->right->left = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->right->left->data = 5;
	root->right->right = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->right->right->data = 89;
	root->left->left->left = unique_ptr<BinaryTreeNode<int>> (new struct BinaryTreeNode<int>);
	root->left->left->left->data = 500;

	struct BinaryTreeNode<int> *ret = find(root, 1);
	if (ret) cout << "Node 1-unbalanced: " << ret->data << endl;
	else cout << "There is no node 1-unbalanced!" << endl;

	return 0;
}
