#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
	TrieNode() : children{} {
		is_word = false;
	}
	
	TrieNode *children[ALPHABET_SIZE];
	bool is_word;
};

class Trie {
public:
	Trie() {
		root = new TrieNode;
	}

	~Trie() {
		// Free all allocated storage.
		free_node(root);
		root = nullptr;
	}
	
	// Insert a word to the trie.
	void insert(const string& s) {
		TrieNode *curr = root;
		for (char c : s) {
			int idx = c - 'a';
			if (curr->children[idx] == nullptr) {
				curr->children[idx] = new TrieNode;
			}
			curr = curr->children[idx];
		}
		
		curr->is_word = true;
	}

	// Shortest prefix of a word that is not a prefix of any string in the trie.
	string prefix(const string& s) {
		TrieNode *curr = root;
		int i;
		for (i = 0; i < s.size(); ++i) {
			int idx = s[i] - 'a';
			if (curr->children[idx]) {
				curr = curr->children[idx];
			} else {
				break;
			}
		}

		if (i == s.size()) {
			return "";
		} else {
			return s.substr(0, i+1);
		}
	}

private:
	void free_node(TrieNode *node) {
		// Delete all descendants.
		for (int i = 0; i < ALPHABET_SIZE; ++i) {
			if (node->children[i]) {
				free_node(node->children[i]);
			}
		}
		
		// Delete this node.
		delete node;
	}
	
private:
	TrieNode *root;
};


// Return the shortest prefix of a string which is not a prefix of any string in a dictionary.
string shortest_prefix(const string& word, const vector<string>& dict) {
	Trie trie;
	for (const string& s : dict) {
		trie.insert(s);
	}

	return trie.prefix(word);
}

int main() {
	string word = "cat";
	vector<string> dict{"dog", "tree", "cow", "cut"};
	string prefix = shortest_prefix(word, dict);
	
	cout << "Word: " << word << ". Dictionary: ";
	for (string& s : dict) {
		cout << s << " ";
	}
	cout << endl;
	cout << "Shorest prefix: " << prefix << endl;
	return 0;
}
