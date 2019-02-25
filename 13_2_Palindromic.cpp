#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Test if a string can be permuted to form a palindrome.
// O(nlgn) with n is the length of string.
bool palindromic(string s) {
	sort(s.begin(), s.end());
	bool has_single = false;
	int count = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i-1] == s[i]) {
			count++;
			if (count > 2) return false;
		} else {
			if (count == 1 && has_single == false)
				has_single = true;
			else if (count == 2)
				count = 1;
			else
				return false;
		}
	}
	if (count == 1 && has_single == true) return false;
	return true;
}

// O(n).
bool palindromic2(string s) {
}

int main() {
	string s = "edified";
	cout << "String \"edified\" is " << (palindromic(s)? "palindromic" : "not palindromic") << endl;
	return 0;
}
