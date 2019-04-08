#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Serialize binary tree using level-order traversal.
string serialize2(TreeNode *root) {
	if (!root) return string();

	ostringstream os;
	vector<string> v;
	queue<TreeNode*> q;
	q.push(root);
	
	while (!q.empty()) {
		TreeNode *node = q.front();
		q.pop();
		if (!node) {
			v.emplace_back("null ");
		} else {
			v.emplace_back(to_string(node->val) + " ");
			q.push(node->left);
			q.push(node->right);
		}
	}
	
	// Trim the last consecutive nulls.
	int last_idx = v.size() - 1;
	for (; last_idx >= 0; last_idx--) {
		if (v[last_idx] != "null ")
			break;
	}

	// Construct the encoded message.
	for (int i = 0; i <= last_idx; i++) {
		os << v[i];
	}
	
	return os.str();
}

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

// Deserialize a message assuming level-order traversal.
TreeNode* deserialize2(string msg) {
	istringstream is(msg);
	vector<TreeNode*> v;

	string token;
	while (is >> token) {
		if (token == "null") {
			v.emplace_back(nullptr);
		} else {
			v.emplace_back(new TreeNode(stoi(token)));
		}
	}

	// i and j are indexes for 2 consecutive levels in the binary tree.
	for (int i = 0, j = 1; j < v.size();) {
		if (v[i] != nullptr) {
			v[i]->left = v[j++];
			if (j < v.size()) {
				v[i]->right = v[j++];
			}
			i++;
		} else {
			i++;
		}
	}

	return v[0];
}

// Deserialize a encoded string, assuming pre-order traversal.
TreeNode* deserialize_preorder(string msg, int& pos) {
	if (pos == msg.size())
		return nullptr;

	size_t next_comma = msg.find_first_of(",", pos);
	string str_val = msg.substr(pos, next_comma - pos);
	pos = next_comma + 1;
	if (str_val == "null") {
		return nullptr;
	}
	
	int val = stoi(str_val);
	TreeNode *node = new TreeNode(val);
	TreeNode *left = deserialize_preorder(msg, pos);
	TreeNode *right = deserialize_preorder(msg, pos);
	node->left = left;
	node->right = right;
	return node;
}

// Deserialize a string to a binary tree.
TreeNode* deserialize(string msg) {
	TreeNode *root = nullptr;
	int pos = 0;
	return deserialize_preorder(msg, pos);
}

void preorder_traverse(TreeNode *node) {
	if (node) {
		cout << node->val << ",";
		preorder_traverse(node->left);
		preorder_traverse(node->right);
	} else {
		cout << "null,";
	}
}

int main() {
	TreeNode *root = new TreeNode(1);
	TreeNode *n1 = new TreeNode(2);
	TreeNode *n2 = new TreeNode(3);
	root->right = n1;
	n1->left = n2;
	string msg = serialize2(root);
	cout << "Encoded message: " << msg << endl;
	cout << "Decoded tree: ";
	preorder_traverse(deserialize2(msg));
	cout << endl;

	// Another tree.
	TreeNode *root2 = new TreeNode(2);
	TreeNode *a1 = new TreeNode(1);
	TreeNode *a2 = new TreeNode(3);
	TreeNode *a3 = new TreeNode(4);
	TreeNode *a4 = new TreeNode(5);
	root2->left = a1;
	root2->right = a2;
	a2->left = a3;
	a2->right = a4;
	string msg2 = serialize2(root2);
	cout << "Encoded message: " << msg2 << endl;
	cout << "Decoded tree: ";
	preorder_traverse(deserialize2(msg2));
	cout << endl;
	
	return 0;
}
