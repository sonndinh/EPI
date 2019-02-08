#include <iostream>
#include <memory>
#include <queue>
#include <utility>

using namespace std;

template <typename T>
struct BinaryTreeNode {
	T data;
	unique_ptr<BinaryTreeNode<T>> left, right;
};

void print(unique_ptr<BinaryTreeNode<int>>& root) {
	queue<int> depths;
	queue<unique_ptr<BinaryTreeNode<int>>> nodes;

	int prev_dep = 0; // depth of previous node.
	depths.push(0); // depth of root node.
	nodes.push(move(root));
	while(!nodes.empty()) {
		unique_ptr<BinaryTreeNode<int>>& node = nodes.front();
		int data = node->data;

		int curr_dep = depths.front(); // depth of the current node
		depths.pop();
		if (curr_dep > prev_dep) {
			cout << endl << data << " ";
			prev_dep = curr_dep;
		} else {
			cout << data << " ";
		}

		if (node->left != nullptr) {
			nodes.push(move(node->left));
			depths.push(curr_dep + 1);
		}
		if (node->right != nullptr) {
			nodes.push(move(node->right));
			depths.push(curr_dep + 1);
		}
		nodes.pop();
	}
	cout << endl;
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

	print(root);

	return 0;
}
