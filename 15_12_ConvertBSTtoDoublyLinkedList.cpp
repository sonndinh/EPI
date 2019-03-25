#include <iostream>
using namespace std;

template <typename T>
struct BSTNode {
	T data;
	BSTNode *left, *right;
};

enum Side {LEFT_SUBTREE, RIGHT_SUBTREE};

// Return the left-most and right-most node of the subtree.
pair<BSTNode<int>*, BSTNode<int>*> helper(BSTNode<int> *curr, BSTNode<int> *parent, Side side) {
	if (!curr) return {nullptr, nullptr};

	auto left = helper(curr->left, curr, LEFT_SUBTREE);
	auto right = helper(curr->right, curr, RIGHT_SUBTREE);

	if (side == LEFT_SUBTREE) {
		if (right.first == nullptr) {
			curr->right = parent;
			parent->left = curr;
		} else {
			curr->right = right.first;
			right.first->left = curr;
		}
		curr->left = left.second;
		if (left.second)
			left.second->right = curr;
	}

	if (side == RIGHT_SUBTREE) {
		if (left.second == nullptr) {
			curr->left = parent;
			parent->right = curr;
		} else {
			curr->left = left.second;
			left.second->right = curr;
		}
		curr->right = right.first;
		if (right.first)
			right.first->left = curr;
	}

	BSTNode<int> *tmp1 = left.first, *tmp2 = right.second;
	if (left.first == nullptr) {
		tmp1 = curr;
	}
	if (right.second == nullptr) {
		tmp2 = curr;
	}
	
	return {tmp1, tmp2};
}

// Convert a BST to a sorted doubly linked list. Return head of the list.
BSTNode<int>* convert(BSTNode<int> *root) {
	auto ret = helper(root, nullptr, RIGHT_SUBTREE);
	return ret.first;
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

	auto head = convert(root);
	print_list(head);
	return 0;
}
