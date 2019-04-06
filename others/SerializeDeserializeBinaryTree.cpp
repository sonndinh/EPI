#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Serialize a binary tree to a string.
// May use level-order to serialize the tree.
string serialize(TreeNode* root) {
	
}

// Deserialize a string to a binary tree.
TreeNode* deserialize(string data) {
	
}

int main() {
	return 0;
}
