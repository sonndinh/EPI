#include <iostream>
#include "common.h"

using namespace std;

// Return true if root is an ancestor of node. False otherwise.
bool is_ancestor(const unique_ptr<BinaryTreeNode<int>>& root, const unique_ptr<BinaryTreeNode<int>>& node) {
	if (root == nullptr) return false;

	// A node is an ancestor of itself.
	if (root == node) return true;

	if (is_ancestor(root->left, node) == true) return true;
	return is_ancestor(root->right, node);
}

const unique_ptr<BinaryTreeNode<int>> gNull = nullptr;

// Compute the lowest common ancestor of 2 nodes in a tree rooted at root.
const unique_ptr<BinaryTreeNode<int>>& lca(const unique_ptr<BinaryTreeNode<int>>& root,
										   const unique_ptr<BinaryTreeNode<int>>& a, bool& ances_a,
										   const unique_ptr<BinaryTreeNode<int>>& b, bool& ances_b) {
	if (a == nullptr || b == nullptr || root == nullptr) return gNull;

	if (root == a) {
		ances_a = true;
		if (is_ancestor(a, b) == true) {
			ances_b = true;
			return a;
		}
		ances_b = false;
		return gNull;
	}
	
	if (root == b) {
		ances_b = true;
		if (is_ancestor(b, a) == true) {
			ances_a = true;
			return b;
		}
		ances_a = false;
		return gNull;
	}

	// Search left subtree
	bool a_cond, b_cond;
	auto& left = lca(root->left, a, a_cond, b, b_cond);
	if (left != nullptr) return left;
	if (a_cond == true && b_cond == false) {
		if (is_ancestor(root->right, b) == true) {
			return root;
		} else {
			ances_a = true;
			ances_b = false;
			return gNull;
		}
	} else if (a_cond == false && b_cond == true) {
		if (is_ancestor(root->right, a) == true) {
			return root;
		} else {
			ances_a = false;
			ances_b = true;
			return gNull;
		}
	} else {
		// root->left is neither ancestor of a nor b.
		ances_a = false;
		ances_b = false;
		return gNull;
	}

	// Search right subtree
	auto& right = lca(root->right, a, a_cond, b, b_cond);
	if (right != nullptr) return right;
	if (a_cond == true && b_cond == false) {
		if (is_ancestor(root->left, b) == true) {
			return root;
		} else {
			ances_a = true;
			ances_b = false;
			return gNull;
		}
	} else if (a_cond == false && b_cond == true) {
		if (is_ancestor(root->left, a) == true) {
			return root;
		} else {
			ances_a = false;
			ances_b = true;
			return gNull;
		}
	} else {
		// root->right is neither ancestor of a nor b.
		ances_a = false;
		ances_b = false;
		return gNull;
	}
	
}

// Shorter implementation counting the number of either node a or b which appear in a given subtree.
// Don't need to consider node a or b specifically.
const unique_ptr<BinaryTreeNode<int>>& helper(const unique_ptr<BinaryTreeNode<int>>& root,
											  const unique_ptr<BinaryTreeNode<int>>& a,
											  const unique_ptr<BinaryTreeNode<int>>& b, int& num_nodes) {
	if (root == nullptr) {
		num_nodes = 0;
		return gNull;
	}
	
	int num_nodes_left;
	auto& left = helper(root->left, a, b, num_nodes_left);
	if (num_nodes_left == 2) return left;

	int num_nodes_right;
	auto& right = helper(root->right, a, b, num_nodes_right);
	if (num_nodes_right == 2) return right;

	if (root == a || root == b) num_nodes = num_nodes_left + num_nodes_right + 1;
	else num_nodes = num_nodes_left + num_nodes_right;

	return (num_nodes == 2? root : gNull);
}

const unique_ptr<BinaryTreeNode<int>>& lca2(const unique_ptr<BinaryTreeNode<int>>& root,
											const unique_ptr<BinaryTreeNode<int>>& a,
											const unique_ptr<BinaryTreeNode<int>>& b) {
	int num_nodes;
	return helper(root, a, b, num_nodes);
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

	//	bool a_bool, b_bool;
	//	const unique_ptr<BinaryTreeNode<int>>& n = lca(root, root->left->left->left, a_bool, root->right->left, b_bool);
	auto& n = lca2(root, root->left->left->left, root->left->right);
	if (n != nullptr) {
		cout << "Ancestor is " << n->data << endl;
	} else {
		cout << "Could not find ancestor!" << endl;
	}
	
	return 0;
}
