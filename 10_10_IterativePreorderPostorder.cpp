#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode *root) {
	stack<TreeNode*> s;
	// The top entry points to the parent of the current node.
	s.push(nullptr); 
	TreeNode *node = root, *prev = nullptr;

	while (node) {
		if (prev == s.top()) {
			// Going down the tree.
			cout << node->val << " ";
			if (node->left) {
				prev = node;
				node = node->left;
				s.push(prev);
			} else if (node->right) {
				prev = node;
				node = node->right;
				s.push(prev);
			} else {
				prev = node;
				node = s.top();
				s.pop();
			}
		} else if (prev == node->left) {
			// Going up from the left child.
			if (node->right) {
				prev = node;
				node = node->right;
				s.push(prev);
			} else {
				prev = node;
				node = s.top();
				s.pop();
			}
		} else {
			// Going up from the right child.
			prev = node;
			node = s.top();
			s.pop();
		}
	}
}

void postorder(TreeNode *root) {
	stack<TreeNode*> s;
	// The top entry points to the parent of the current node.
	s.push(nullptr); 
	TreeNode *node = root, *prev = nullptr;

	while (node) {
		if (prev == s.top()) {
			// Going down the tree.
			if (node->left) {
				prev = node;
				node = node->left;
				s.push(prev);
			} else if (node->right) {
				prev = node;
				node = node->right;
				s.push(prev);
			} else {
				cout << node->val << " ";
				prev = node;
				node = s.top();
				s.pop();
			}
		} else if (prev == node->left) {
			// Going up from the left child.
			if (node->right) {
				prev = node;
				node = node->right;
				s.push(prev);
			} else {
				cout << node->val << " ";
				prev = node;
				node = s.top();
				s.pop();
			}
		} else {
			// Going up from the right child.
			cout << node->val << " ";
			prev = node;
			node = s.top();
			s.pop();
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
	n1->left = n3; n1->right = n4;
	n2->left = n5;
	
	cout << "Preorder traversal: ";
	preorder(root);
	cout << endl;

	cout << "Postorder traversal: ";
	postorder(root);
	cout << endl;
	return 0;
}
