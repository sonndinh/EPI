#include <iostream>
#include <vector>
#include "common.h"
using namespace std;

enum Type {PREORDER, POSTORDER};

// Insert key to a correct position in a BST.
void insert(int key, BSTNode<int> *root) {
	BSTNode<int> *curr = root, *parent = nullptr;
	while (curr) {
		parent = curr;
		if (curr->data < key) {
			curr = curr->right.get();
		} else {
			curr = curr->left.get();
		}
	}
	BSTNode<int> *node = new BSTNode<int>{key, nullptr, nullptr};
	if (parent->data < key) {
		parent->right = unique_ptr<BSTNode<int>> (node);
	} else {
		parent->left = unique_ptr<BSTNode<int>> (node);
	}
}

// Reconstruct an unique BST from a preorder or postorder traversal key sequence.
// An unique BST cannot be reconstructed from an inorder traversal.
// Assuming keys are distinct.
BSTNode<int>* reconstruct(const vector<int>& A, Type order) {
	BSTNode<int> *root = nullptr;
	
	if (order == PREORDER) {
		for (int i = 0; i < A.size(); i++) {
			if (root == nullptr) {
				root = new BSTNode<int>{A[i], nullptr, nullptr};
			} else {
				// Put the node to the correct position from the root.
				int key = A[i];
				insert(key, root);
			}
		}
	} else {
		for (int i = A.size()-1; i >=0; i--) {
			if (root == nullptr) {
				root = new BSTNode<int>{A[i], nullptr, nullptr};
			} else {
				int key = A[i];
				insert(key, root);
			}
		}
	}
	return root;
}

void print(BSTNode<int> *node) {
	if (!node) return;
	print(node->left.get());
	cout << node->data << " ";
	print(node->right.get());
}

int main() {
	vector<int> preorder{5,3,2,1,4,7,6,8,9};
	vector<int> postorder{1,2,4,3,6,9,8,7,5};
	auto root1 = reconstruct(preorder, PREORDER);
	auto root2 = reconstruct(postorder, POSTORDER);

	cout << "Tree reconstructed from a preorder traversal: ";
	print(root1); cout << endl;
	cout << "Tree reconstructed from a postorder traversal: ";
	print(root2); cout << endl;
	
	return 0;
}
