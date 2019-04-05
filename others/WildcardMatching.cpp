#include <iostream>
#include <string>
using namespace std;


// Recursive implementation.
bool is_match_helper(const string& s, int i, const string& p, int j) {
	if (j >= p.size() && i < s.size())
		return false;
	if (j < p.size() && i >= s.size()) {
		
	}
		
	if (p[j] == '*') {
		return is_match_helper(s, i, p, j+1) || is_match_helper(s, i+1, p, j+1)
			|| is_match_helper(s, i+1, p, j);
	}

	if (p[j] == '?' || p[j] == s[i]) {
		return is_match_helper(s, i+1, p, j+1);
	}
}

// Implement wildcard pattern matching.
// '?' matches any single character.
// '*' matches any sequence of characters, including empty.
// E.g., ("aab", "c*a*b") -> 0 (not match).
int is_match(const string& s, const string& p) {
	return (is_match_helper(s, 0, p, 0)? 1 : 0);
}

int main() {
	is_match("aab", "c*a*b");
	return 0;
}
