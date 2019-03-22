#include <iostream>
#include "common.h"
using namespace std;

// Find the lowest common ancestor of 2 nodes in a BST.
// Assuming all keys are distinct and s.key < b.key.
BSTNode<int>* lca(const unique_ptr<BSTNode<int>>& root, const unique_ptr<BSTNode<int>>& s,
				  const unique_ptr<BSTNode<int>>& b) {
	BSTNode<int> *curr = root.get();
	
	while (curr != s.get() && curr != b.get()) {
		if (curr->data > s->data && curr->data < b->data) {
			break;
		} else if (curr->data < s->data){
			curr = curr->right.get();
		} else {
			curr = curr->left.get();
		}
	}
	return curr;
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

	//	auto &s = root->left->right;
	auto &s = root;
	auto &b = root->right->left;
	auto ret = lca(root, s, b);
	cout << "LCA of " << s->data << " and " << b->data << ": " << ret->data << endl;
	
	return 0;
}
