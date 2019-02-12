#include <iostream>
#include "common.h"

using namespace std;

// Get depth of node a in a given binary tree.
int depth(shared_ptr<BinaryTreeNode2<int>>& root, shared_ptr<BinaryTreeNode2<int>>& n) {
	int d = 0;
	shared_ptr<BinaryTreeNode2<int>>& tmp = n;
	// Parent pointer of root node is null.
	while (tmp->parent != nullptr) {
		d++;
		tmp = tmp->parent;
	}
	return d;
}

const shared_ptr<BinaryTreeNode2<int>>& lca(shared_ptr<BinaryTreeNode2<int>>& root,
											shared_ptr<BinaryTreeNode2<int>>& a,
											shared_ptr<BinaryTreeNode2<int>>& b) {
	int a_dep = depth(root, a);
	int b_dep = depth(root, b);
	shared_ptr<BinaryTreeNode2<int>>& lower_node = a_dep < b_dep ? b : a;
	shared_ptr<BinaryTreeNode2<int>>& higher_node = a_dep < b_dep ? a : b;
	int diff = abs(a_dep - b_dep);

	while (diff > 0) {
		lower_node = lower_node->parent;
		diff--;
	}

	if (lower_node == higher_node) return higher_node;
	while(lower_node != higher_node) {
		lower_node = lower_node->parent;
		higher_node = higher_node->parent;
	}

	return higher_node;
}

int main() {
	shared_ptr<BinaryTreeNode2<int>> leave1(new struct BinaryTreeNode2<int>);
	leave1->data = 500;
	shared_ptr<BinaryTreeNode2<int>> leave2(new struct BinaryTreeNode2<int>);
	leave2->data = 561;
	shared_ptr<BinaryTreeNode2<int>> leave3(new struct BinaryTreeNode2<int>);
	leave3->data = 5;
	shared_ptr<BinaryTreeNode2<int>> leave4(new struct BinaryTreeNode2<int>);
	leave4->data = 89;
	leave1->parent = unique_ptr<BinaryTreeNode2<int>> (new struct BinaryTreeNode2<int>);
	leave1->parent->data = 271;
	leave2->parent = unique_ptr<BinaryTreeNode2<int>> (new struct BinaryTreeNode2<int>);
	leave2->parent->data = 67;
	leave1->parent->parent = leave2->parent;
	leave3->parent = unique_ptr<BinaryTreeNode2<int>> (new struct BinaryTreeNode2<int>);
	leave3->parent->data = 76;
	leave4->parent = leave3->parent;
	leave3->parent->parent = unique_ptr<BinaryTreeNode2<int>> (new struct BinaryTreeNode2<int>);
	leave3->parent->parent->data = 314;
	leave2->parent->parent = leave3->parent->parent;
	shared_ptr<BinaryTreeNode2<int>> root = leave2->parent->parent;

	auto& n = lca(root, leave1, leave3);
	cout << "LCA is: " << n->data << endl;
	
	return 0;
}
