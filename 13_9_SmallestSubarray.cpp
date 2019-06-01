#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

// Return the starting and ending indexes of a smallest subarray that covers the keywords.
// Time complexity: O(n), space: O(m), where n is the size of the input array, m is the number of keywords.
pair<int, int> smallest_subarray(const vector<string>& text, const unordered_set<string>& keywords) {
	if (text.empty() || keywords.empty()) return {-1, -1};
	
	int start = 0, end = 0;
	int n = text.size();

	// Map each keyword covered with its number of appearance in current subarray.
	unordered_map<string, int>  cover;
	if (keywords.count(text[start]) > 0) {
		cover[text[start]]++;
	}

	// Length of a smallest subarray that covers all keywords.
	int min_start = -1, min_end = -1;
	int min_length = n+1;
	
	// Maintain an invariant that @start is always less than or equal to @end.
	for (; start < n && end < n && start <= end; ) {
		if (cover.size() == keywords.size()) {
			if (end - start + 1 < min_length) {
				// Found a smaller satisfying subarray.
				min_start = start;
				min_end = end;
				min_length = end - start + 1;
			}
			
			// Move the @start index forward.
			++start;
			string prev = text[start - 1];
			if (keywords.count(prev) > 0) {
				cover[prev]--;
				if (cover[prev] == 0) cover.erase(prev);
			}
		} else {
			// Move the @end index forward.
			++end;
			if (end < n && keywords.count(text[end]) > 0) {
				cover[text[end]]++;
			}
		}
	}

	return {min_start, min_end};
}

int main() {
	string str = "My paramount object in this struggle is to save the Union and is not either \
to save or to destroy slavery If I could save the Union without freeing any slave I would do it \
and if I could save it by freeing all the slaves I would do it and if I could save it by freeing \
some and leaving others alone I would also do that";
	vector<string> text;
	stringstream ss(str);
	string word;
	while (ss >> word) {
		text.emplace_back(word);
	}

	for (string& s : text)
		cout << s << " ";
	cout << endl;
	
	unordered_set<string> keywords{"Union", "save"};
    auto ret = smallest_subarray(text, keywords);

	cout << "Smallest subarray is [" << ret.first << ", " << ret.second << "]" << endl;
	
	return 0;
}
