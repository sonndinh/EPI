#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	double remain_cap;
	vector<double> items;
	TreeNode *left, *right, *parent;
};

TreeNode* build_tree(vector<TreeNode*> nodes) {
	if (nodes.size() == 1) return nodes[0];

	vector<TreeNode*> tmp;
	int i = 0;
	while (i < nodes.size() - 1) {
		auto left = nodes[i];
		auto right = nodes[++i];
		TreeNode *p = new TreeNode{1.0, vector<double>(), left, right, nullptr};
		left->parent = p;
		right->parent = p;
		tmp.emplace_back(p);
		i++;
	}
	if (i == nodes.size() - 1)
		tmp.push_back(nodes.back());
	
	return build_tree(tmp);
}

void update(TreeNode *node) {
	if (!node) return;
	node->remain_cap = max(node->left->remain_cap, node->right->remain_cap);
	update(node->parent);
}

void insert(double item, TreeNode *node) {
	if (node->left == nullptr && node->right == nullptr) {
		node->remain_cap -= item;
		node->items.push_back(item);
		update(node->parent);
		return;
	}

	if (item <= node->left->remain_cap)
		insert(item, node->left);
	else
		insert(item, node->right);
}

// Implement first-fit heuristic in O(nlgn). Assuming boxes has capacity of 1.0, and
// items have size at most 1.0.
vector<TreeNode*> first_fit(const vector<double>& items) {
	int n = items.size();

	// Each leaf corresponds to a box.
	vector<TreeNode*> leaves;
	for (int i = 0; i < n; i++) {
		leaves.emplace_back(new TreeNode{1.0, vector<double>(), nullptr, nullptr, nullptr});
	}

	// Build the tree.
	auto root = build_tree(leaves);

	// Insert items.
	for (double item : items) {
		insert(item, root);
	}
	return leaves;
}

int main() {
	vector<double> items{0.4, 0.12, 0.5, 0.8, 0.1, 0.08, 0.6, 0.74, 0.23};
	auto boxes = first_fit(items);
	cout << "Items: " << endl;
	for (double i : items) {
		cout << i << " ";
	}
	cout << endl;
	int i = 0;
	for (TreeNode *p : boxes) {
		cout << "Box " << i++ << " :";
		for (double i : p->items) {
			cout << i << " ";
		}
		cout << endl;
	}
	
	return 0;
}
