#include <iostream>
#include <vector>
#include "common.h"
using namespace std;

void find(const unique_ptr<BSTNode<int>>& node, vector<int>& ret, int& k) {
	if (k == 0 || node == nullptr) return;

	find(node->right, ret, k);
	if (k > 0) {
		ret.push_back(node->data);
		k--;
	}
	find(node->left, ret, k);
}

// Return k largest elements in a given binary search tree.
vector<int> k_largest(const unique_ptr<BSTNode<int>>& root, int k) {
	vector<int> ret;
	find(root, ret, k);
	return ret;
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

	auto ret = k_largest(root, 2);
	cout << "3 largest elements: ";
	for (int a : ret) {
		cout << a << " ";
	}
	cout << endl;
	return 0;
}
