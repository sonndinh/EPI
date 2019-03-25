#include <iostream>
using namespace std;

template <typename T>
struct BSTNode {
	T data;
	BSTNode *left, *right;
};

enum Side {LEFT_SUBTREE, RIGHT_SUBTREE};

// Inorder traverse the BST. Return the right most node for the left subtree or
// the left most node for the right subtree.
BSTNode<int>* helper(BSTNode<int> *curr, BSTNode<int> **head, BSTNode<int> *parent, Side side) {
	if (!curr) return nullptr;

	if (side == LEFT_SUBTREE && curr->left == nullptr && *head == nullptr)
		*head = curr;
	
	BSTNode<int> *right_most = helper(curr->left, head, curr, LEFT_SUBTREE);
	BSTNode<int> *left_most = helper(curr->right, head, curr, RIGHT_SUBTREE);

	// Rewrite the left pointer to point to previous node, and
	// the right pointer to point to the next node.
	if (side == LEFT_SUBTREE) {
		if (!right_most) {
			curr->right = parent;
		} else {
			curr->right = left_most;
		}
		curr->left = right_most;
	}
	
	if (side == RIGHT_SUBTREE) {
		if (!left_most) {
			curr->left = parent;
		} else {
			curr->left = left_most;
		}
		curr->right = right_most;
	}
		
	if ((side == LEFT_SUBTREE && !right_most) || (side == RIGHT_SUBTREE && !left_most)) {
		return curr;
	}
	
	return (side == LEFT_SUBTREE ? right_most : left_most);
}

// Convert a BST to a sorted doubly linked list. Return head of the list.
BSTNode<int>* convert(BSTNode<int> *root) {
	BSTNode<int> *head = nullptr;
	helper(root, &head, nullptr, RIGHT_SUBTREE);
	return head;
}

void print_list(BSTNode<int> *head) {
	auto curr = head;
	while (curr) {
		cout << curr->data << " ";
		curr = curr->right;
	}
	cout << endl;
}

int main() {
   	BSTNode<int> *root = new BSTNode<int> {0, nullptr, nullptr};
	root->data = 7;
	root->left = new BSTNode<int> {0, nullptr, nullptr};
	root->left->data = 3;
	root->right = new BSTNode<int> {0, nullptr, nullptr};
	root->right->data = 11;
	root->left->left = new BSTNode<int> {0, nullptr, nullptr};
	root->left->left->data = 2;
	root->left->right = new BSTNode<int> {0, nullptr, nullptr};
	root->left->right->data = 5;
	/*
	root->right->left = unique_ptr<BSTNode<int>> (new BSTNode<int>);
	root->right->left->data = 320;
	root->right->right = unique_ptr<BSTNode<int>> (new BSTNode<int>);
	root->right->right->data = 400;
	root->left->left->left = unique_ptr<BSTNode<int>> (new BSTNode<int>);
	root->left->left->left->data = 50;
	*/

	auto head = convert(root);
	print_list(head);
	return 0;
}
