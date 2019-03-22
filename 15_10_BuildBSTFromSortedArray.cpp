#include <iostream>
#include <vector>
#include "common.h"
using namespace std;

BSTNode<int>* helper(const vector<int>& A, int s, int t) {
	if (s > t) return nullptr;
	
	int mid = s + (t-s)/2;
	BSTNode<int> *l = helper(A, s, mid-1);
	BSTNode<int> *r = helper(A, mid+1, t);
	BSTNode<int> *curr = new BSTNode<int>;
	curr->data = A[mid];
	curr->left = unique_ptr<BSTNode<int>> (l);
	curr->right = unique_ptr<BSTNode<int>> (r);
	return curr;
}

// Build a BST from a sorted array.
BSTNode<int>* build_bst(const vector<int>& A) {
	return helper(A, 0, A.size()-1);
}

void print_bst(BSTNode<int> *node) {
	if (!node) return;
	
	print_bst(node->left.get());
	cout << node->data << " ";
	print_bst(node->right.get());
}

int main() {
	vector<int> A{1,2,3,4,5,6,7,8,9,10,11,12};
	BSTNode<int> *root = build_bst(A);
	print_bst(root); cout << endl;
	return 0;
}
