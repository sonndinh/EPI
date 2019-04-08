#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	char val;
	TreeNode *left, *right;
	TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

// Reconstruct a binary tree from inorder and preorder traversals.
// Assuming keys are distinct.
TreeNode* reconstruct(vector<char> in, vector<char> pre) {
	if (in.empty()) return nullptr;

	char val = pre[0];
	TreeNode *node = new TreeNode(val);
	vector<char>::iterator it = find(in.begin(), in.end(), val);
	vector<char> in_left(in.begin(), it);
	vector<char> in_right(it + 1, in.end());
	vector<char> pre_left(pre.begin() + 1, pre.begin() + 1 + in_left.size());
	vector<char> pre_right(pre.begin() + 1 + in_left.size(), pre.end());

	node->left = reconstruct(in_left, pre_left);
	node->right = reconstruct(in_right, pre_right);
	return node;
}

void preorder_traverse(TreeNode *node) {
	if (node) {
		cout << node->val << ",";
		preorder_traverse(node->left);
		preorder_traverse(node->right);
	} 
}

int main() {
	vector<char> inorder{'F', 'B', 'A', 'E', 'H', 'C', 'D', 'I', 'G'};
	vector<char> preorder{'H', 'B', 'F', 'E', 'A', 'C', 'D', 'G', 'I'};
	TreeNode *root = reconstruct(inorder, preorder);

	cout << "Preorder traversal: ";
	preorder_traverse(root);
	cout << endl;
	return 0;
}
