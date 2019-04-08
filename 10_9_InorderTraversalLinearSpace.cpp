#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *parent;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), parent(nullptr), left(nullptr), right(nullptr) {}
};


void inorder_traversal(TreeNode *root) {
	if (!root) return;
	
	// Keep a pointer to the node traversed in the previous iteration.
	// This keeps track what steps have been finished.
	TreeNode *node = root, *prev = nullptr;

	while (node) {
		if (prev == node->parent) {
			// Going down the tree.
			if (node->left) {
				// Go left.
				prev = node;
				node = node->left;
			} else {
				cout << node->val << " ";
				if (node->right) {
					// Go right.
					prev = node;
					node = node->right;
				} else {
					// Reach leave, backtrack now.
					prev = node;
					node = node->parent;
				}
			}
		} else if (prev == node->left) {
			// Going up the tree from the left child.
			cout << node->val << " ";
			if (node->right) {
				prev = node;
				node = node->right;
			} else {
				prev = node;
				node = node->parent;
			}
		} else {
			// Going up the tree from the right child.
			prev = node;
			node = node->parent;
		}
	}
}
	
int main() {
	TreeNode *root = new TreeNode(1);
	TreeNode *n1 = new TreeNode(2);
	TreeNode *n2 = new TreeNode(3);
	TreeNode *n3 = new TreeNode(5);
	TreeNode *n4 = new TreeNode(4);
	TreeNode *n5 = new TreeNode(6);
	root->left = n1; root->right = n2;
	n1->parent = root; n2->parent = root;
	n1->left = n3; n1->right = n4;
	n3->parent = n1; n4->parent = n1;
	n2->left = n5;
	n5->parent = n2;
	
	cout << "Inorder traversal: ";
	inorder_traversal(root);
	cout << endl;
	
	return 0;
}
