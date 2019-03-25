#include <iostream>
using namespace std;

template<typename T>
struct BSTNode {
	T data;
	BSTNode *left, *right;
};

// Helper for converting a soted linked list to BST.
BSTNode<int>* convert_helper(BSTNode<int> **head, int n) {
	if (n <= 0) {
		return nullptr;
	}
	
	auto left_root = convert_helper(head, n/2);
	auto root = *head;
	*head = (*head)->right;
	auto right_root = convert_helper(head, n - n/2 - 1);
	root->left = left_root;
	root->right = right_root;

	return root;
}

// Convert a sorted doubly linked list to a BST.
BSTNode<int>* linked_list_to_bst(BSTNode<int> *L) {
	auto curr = L;
	int n = 0;
	while (curr) {
		++n;
		curr = curr->right;
	}

	return convert_helper(&L, n);
}

BSTNode<int>* merge_lists(BSTNode<int> *L1, BSTNode<int> *L2) {
	auto curr1 = L1;
	auto curr2 = L2;
	BSTNode<int> *head = nullptr, *prev = nullptr;

	while (curr1 && curr2) {
		if (!prev) {
			if (curr1->data < curr2->data) {
				prev = curr1;
				curr1 = curr1->right;
			} else {
				prev = curr2;
				curr2 = curr2->right;
			}
			head = prev;
		} else {
			if (curr1->data < curr2->data) {
				prev->right = curr1;
				curr1->left = prev;
				prev = curr1;
				curr1 = curr1->right;
			} else {
				prev->right = curr2;
				curr2->left = prev;
				prev = curr2;
				curr2 = curr2->right;
			}
		}
	}
	if (!curr1) {
		prev->right = curr2;
		curr2->left = prev;
	} else if (!curr2) {
		prev->right = curr1;
		curr1->left = prev;
	}
	
	return head;
}

BSTNode<int>* bst_to_linked_list(BSTNode<int> *root);

// Merge 2 BSTs in O(n) time, with n is the total number of nodes.
BSTNode<int>* merge_bst(BSTNode<int> *A, BSTNode<int> *B) {
	// Convert 2 BSTs to sorted doubly linked lists.
	BSTNode<int> *L1 = bst_to_linked_list(A);
	BSTNode<int> *L2 = bst_to_linked_list(B);
	
	// Merge to 2 linked lists.
	BSTNode<int> *L = merge_lists(L1, L2);

	// Convert the merged linked list to a BST.
	return linked_list_to_bst(L);
}

void print_bst(BSTNode<int> *node) {
	if (!node) return;
	print_bst(node->left);
	cout << node->data << " ";
	print_bst(node->right);
}

int main() {
	BSTNode<int> *n1 = new BSTNode<int> {17, nullptr, nullptr};
	BSTNode<int> *n2 = new BSTNode<int> {5, nullptr, nullptr};
	BSTNode<int> *n3 = new BSTNode<int> {23, nullptr, nullptr};
	BSTNode<int> *n4 = new BSTNode<int> {2, nullptr, nullptr};
	BSTNode<int> *n5 = new BSTNode<int> {11, nullptr, nullptr};
	n1->left = n2; n1->right = n3;
	n2->left = n4; n2->right = n5;

	BSTNode<int> *m1 = new BSTNode<int> {13, nullptr, nullptr};
	BSTNode<int> *m2 = new BSTNode<int> {7, nullptr, nullptr};
	BSTNode<int> *m3 = new BSTNode<int> {19, nullptr, nullptr};
	BSTNode<int> *m4 = new BSTNode<int> {3, nullptr, nullptr};
	m1->left = m2; m1->right = m3;
	m2->left = m4;

	auto root = merge_bst(n1, m1);
	print_bst(root); cout << endl;
	return 0;
}
