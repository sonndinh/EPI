#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

// Find the smallest subarray of @text that covers all words in @keywords in the given order.
// Words in @keywords are distinct.
pair<int, int> smallest_subarray_sequential(const vector<string>& text, const vector<string>& keywords) {
	if (text.empty() || keywords.empty()) return {-1, -1};

	int start = 0, end = 0;
	
	return {start, end};
}

int main() {
	return 0;
}
