#include <iostream>
#include <unordered_map>
#include <map>
#include <queue>
#include <string>
using namespace std;

// Huffman tree node.
struct TreeNode {
	char c;
	double freq;
	TreeNode *left, *right;
};

// Compare two tree nodes using their frequencies.
struct FreqCompare {
	bool operator() (const TreeNode *first, const TreeNode *second) {
		return (first->freq > second->freq);
	}
};

void get_code_words_helper(map<char, string>& ret, TreeNode *node, string& code) {
	if (node->left == nullptr && node->right == nullptr) {
		ret.emplace(make_pair(node->c, code));
		return;
	}

	code = code + "0";
	get_code_words_helper(ret, node->left, code);
	code = code.erase(code.size()-1); // Remove the last digit.
	code = code + "1";
	get_code_words_helper(ret, node->right, code);
	code = code.erase(code.size()-1); // Remove the last digit again.
}

void get_code_words(map<char, string>& ret, TreeNode *root) {
	string code;
	get_code_words_helper(ret, root, code);
}

// Return a code book for a set of symbols with their frequencies.
map<char, string> huffman_coding(const unordered_map<char, double>& frequencies) {
	priority_queue<TreeNode*, vector<TreeNode*>, FreqCompare> min_heap;
	// Insert the symbols and their frequencies to the min-heap.
	for (const pair<char, double>& p : frequencies) {
		min_heap.emplace(new TreeNode{p.first, p.second, nullptr, nullptr});
	}

	while (min_heap.size() > 1) {
		TreeNode *first = min_heap.top(); min_heap.pop();
		TreeNode *second = min_heap.top(); min_heap.pop();
		
		// Create a parent node.
		TreeNode *tmp = new TreeNode;
		tmp->freq = first->freq + second->freq;
		tmp->left = first;
		tmp->right = second;
		min_heap.emplace(tmp);
	}
	TreeNode *root = min_heap.top();

	// Retrieve the code word for each symbol.
	map<char, string> ret;
	get_code_words(ret, root);
	return ret;
}

int main() {
	unordered_map<char, double> freq{{'a', 8.17}, {'b', 1.49}, {'c', 2.78}, {'d', 4.25}, {'e', 12.7}, {'f', 2.23},
									 {'g', 2.02}, {'h', 6.09}, {'i', 6.97}, {'j', 0.15}, {'k', 0.77}, {'l', 4.03},
									 {'m', 2.41}, {'n', 6.75}, {'o', 7.51}, {'p', 1.93}, {'q', 0.1}, {'r', 5.99},
									 {'s', 6.33}, {'t', 9.06}, {'u', 2.76}, {'v', 0.98}, {'w', 2.36}, {'x', 0.15},
									 {'y', 1.97}, {'z', 0.07}};
	auto code_book = huffman_coding(freq);
	for (auto p : code_book) {
		cout << p.first << ": " << p.second << endl;
	}
	return 0;
}
