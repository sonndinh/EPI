#include <iostream>
#include <string>
using namespace std;


// Recursive implementation.
bool is_match_helper(const string& s, int i, const string& p, int j) {
	// Some characters in the text do not match.
	if (j >= p.size() && i < s.size())
		return false;

	// Some characters left in the pattern.
	if (j < p.size() && i >= s.size()) {
		if (p[j] == '*')
			return is_match_helper(s, i, p, j+1);
		else
			return false;
	}

	// All characters match.
	if (j >= p.size() && i >= s.size())
		return true;
		
	if (p[j] == '*') {
		return is_match_helper(s, i, p, j+1) || is_match_helper(s, i+1, p, j+1)
			|| is_match_helper(s, i+1, p, j);
	}

	if (p[j] == '?' || p[j] == s[i]) {
		return is_match_helper(s, i+1, p, j+1);
	}
	
	return false;
}

// Implement wildcard pattern matching.
// '?' matches any single character.
// '*' matches any sequence of characters, including empty.
// E.g., ("aab", "c*a*b") -> 0 (not match).
int is_match(const string& s, const string& p) {
	return (is_match_helper(s, 0, p, 0)? 1 : 0);
}

int main() {
	string s = "aa", s2 = "aab", s3 = "ab", s4 = "bb", s5 = "abcd";
	string p = "aa*", p2 = "aaa", p3 = "?*", p4 = "*", p5 = "*??**";
	cout << "String: " << s << ", pattern: " << p << ": " << (is_match(s, p)? "Match" : "Not match") << endl;
	cout << "String: " << s2 << ", pattern: " << p2 << ": " << (is_match(s2, p2)? "Match" : "Not match") << endl;
	cout << "String: " << s3 << ", pattern: " << p3 << ": " << (is_match(s3, p3)? "Match" : "Not match") << endl;
	cout << "String: " << s4 << ", pattern: " << p4 << ": " << (is_match(s4, p4)? "Match" : "Not match") << endl;
	cout << "String: " << s5 << ", pattern: " << p5 << ": " << (is_match(s5, p5)? "Match" : "Not match") << endl;
	return 0;
}
