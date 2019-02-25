#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// O(n) time. O(m) space with m is the number of distinct characters.
bool palindromic(string s) {
	unordered_map<char, int> dict;
	for (int i = 0; i < s.size(); i++) {
		dict[s[i]]++;
	}

	int count_odds = 0;
	for (const pair<char, int>& p : dict) {
		if (p.second % 2 == 1)
			count_odds++;
	}
	return count_odds == 0 || count_odds == 1;
}

int main() {
	string s = "ediffied";
	cout << "String \"ediffied\" is " << (palindromic(s)? "palindromic" : "NOT palindromic") << endl;
	return 0;
}
