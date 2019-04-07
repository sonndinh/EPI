#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Use pre-order traversal. Use "null" to indicate empty children.
void serialize_preorder(TreeNode *root, TreeNode *node, string& msg) {
	if (!node) {
		msg += ",null";
		return;
	}

	if (node == root) {
		msg += to_string(root->val);
	} else {
		msg += "," + to_string(node->val);
	}

	serialize_preorder(root, node->left, msg);
	serialize_preorder(root, node->right, msg);
}

// Serialize a binary tree to a string.
string serialize(TreeNode* root) {
	if (!root) return string();
	
	string encoded_msg;
	serialize_preorder(root, root, encoded_msg);
	return encoded_msg;
}

// Deserialize a encoded string, assuming pre-order traversal.
TreeNode* deserialize_preorder(string msg, int pos) {
	if (pos == msg.size())
		return nullptr;

	size_t next_comma = msg.find_first_of(",", pos);
	string str_val = msg.substr(pos, next_comma - pos);
	if (str_val == "null")
		return nullptr;
	
	int val = stoi(str_val);
	TreeNode *node = new TreeNode(val);
	
	return node;
}

// Deserialize a string to a binary tree.
TreeNode* deserialize(string msg) {
	TreeNode *root = nullptr;
	return deserialize_preorder(msg, 0);
}

int main() {
	TreeNode *root = new TreeNode(1);
	TreeNode *n1 = new TreeNode(2);
	TreeNode *n2 = new TreeNode(3);
	root->right = n1;
	n1->left = n2;
	string msg = serialize(root);
	cout << "Encoded message: " << msg << endl;
	return 0;
}
