#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>

using namespace std;

// Find all substring of a text that are permutations of a set of words.
// All words have the same length.
vector<pair<int, string>> decompose(string text, unordered_set<string> words) {
	if (words.size() == 0) return vector<pair<int, string>>();
	
	vector<pair<int, string>> ret;
	int len_w = words.begin()->size();
	// Build a map from indices in the input text to valid words.
	unordered_map<int, string> idx_to_word;
	// This takes O(n-w) with n is the length of the text and w is the largest length of a word.
	for (int i = 0; i <= text.size()-len_w; i++) {
		string tmp = text.substr(i, len_w);
		if (words.find(tmp) != words.cend()) {
			idx_to_word[i] = tmp;
		}
	}

	int num_w = words.size();
	// This loop takes O((n-w)m)
	for (const pair<int, string>& p : idx_to_word) {
		int idx = p.first;
		string str = p.second;
		string concat;

		// Store the set of words that are already used for concatenation.
		unordered_set<string> storage;
		// This takes O(m) with m is the number of words.
		while (!words.empty()) {
			auto it = idx_to_word.find(idx);
			if (it != idx_to_word.cend()) {
				concat += it->second;
				storage.emplace(it->second);
				words.erase(it->second);
				idx += len_w;
			} else {
				// Restore the original set of words.
				for (const string& s : storage) {
					words.emplace(s);
				}
				storage.clear();
				break;
			}
		}
		if (words.empty()) {
			ret.emplace_back(p.first, concat);
			words = std::move(storage);
		}
	}
	
	return ret;
}

int main() {
	unordered_set<string> words = {"can", "apl", "ana"};
	string text = "amanaplanacanal";
	vector<pair<int, string>> ret = decompose(text, words);
	cout << "Concatenations for text " << text << ": ";
	for (const pair<int, string>& p : ret) {
		cout << "<" << p.first << ", " << p.second << "> ";
	}
	cout << endl;
	return 0;
}
