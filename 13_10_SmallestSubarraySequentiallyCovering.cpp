#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <sstream>
using namespace std;

// Find the smallest subarray of @text that covers all words in @keywords in the given order.
// Words in @keywords are distinct.
pair<int, int> smallest_subarray_sequential(const vector<string>& text, const vector<string>& keywords) {
	if (text.empty() || keywords.empty()) return {-1, -1};

	unordered_map<string, int> key_to_idx;
	for (int i = 0; i < keywords.size(); ++i) {
		key_to_idx.emplace(keywords[i], i);
	}

	pair<int, int> result{-1, -1};
	
	// Map from each keyword to its most recent occurrence in the text and
	// the length of smallest subarray ending at that index that covers all keywords up to that keyword.
	// Inside a pair, first entry is index of most recent occurrence, second entry is its smallest length.
	unordered_map<string, pair<int, int>> keyword_to_occ;
	int min_subarray_length = text.size() + 1;

	for (int i = 0; i < text.size(); ++i) {
		string word = text[i];
		if (key_to_idx.count(word) > 0) {
			// Found a keyword.
			int idx = key_to_idx[word];
			if (idx > 0) {
				string prev_key = keywords[idx-1];
				if (keyword_to_occ.find(prev_key) != keyword_to_occ.end()) {
					int most_recent_occur = keyword_to_occ[prev_key].first;
					int prev_length = keyword_to_occ[prev_key].second;
					int length = prev_length + (i - most_recent_occur);
					if (idx == keywords.size() - 1 && length < min_subarray_length) {
						min_subarray_length = length;
						result = {i - length + 1, i};
					}
					
					// Update the most recent occurrence of the current keyword.
					keyword_to_occ[word] = {i, length};
				}
			} else {
				// This is the first keyword. We just update its recent occurrence information.
				keyword_to_occ[word] = {i, 1};
				if (idx == keywords.size() - 1) {
					// There is only 1 keyword in the input.
					min_subarray_length = 1;
					result = {i, i};
				}
			}
		}
	}
	
	return result;
}

int main() {
	string str = "My paramount object in this struggle is to save the Union and is not either \
to save or to destroy slavery If I could save the Union without freeing any slave I would do it \
and if I could save it by freeing all the slaves I would do it and if I could save it by freeing \
some and leaving others alone I would also do that";
	stringstream ss(str);
	string temp;
	vector<string> text;
	while (ss >> temp) {
		text.emplace_back(temp);
	}

	vector<string> keywords{"Union", "save"};

	pair<int, int> ret = smallest_subarray_sequential(text, keywords);
	cout << "Smallest subarray: [" << ret.first << ", " << ret.second << "]" << endl;
	
	return 0;
}
