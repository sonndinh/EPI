#include <iostream>
#include "common.h"

using namespace std;

// Return the first entry that is larger than k in inorder traversal.
BSTNode<int>* find(const unique_ptr<BSTNode<int>>& node, int k) {
	BSTNode<int> *curr = node.get();
	BSTNode<int> *first = nullptr;
	bool found = false;
	
	while (curr != nullptr) {
		if (curr->data == k) {
			found = true;
			curr = curr->right.get();
		} else if (curr->data > k) {
			first = curr;
			curr = curr->left.get();
		} else {
			curr = curr->right.get();
		}
	}
	return found? first : nullptr;
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

	int k = 320;
	BSTNode<int> *ret = find(root, k);
	if (ret) {
		cout << "First node larger than " << k << ": " << ret->data << endl;
	} else {
		cout << "Not Found a node larger than " << k << endl;
	}
	return 0;
}
