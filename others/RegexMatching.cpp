#include <iostream>
#include <vector>
using namespace std;

// Return whether a string matches a pattern.
// A '.' matches any single character. A '*' matches zero or more
// preceding character in the pattern. 
bool match(string txt, string pat) {
	int n = txt.size();
	int m = 0; // '*' is grouped with its preceding character.
	for (int i = pat.size()-1; i >= 0; i--) {
		if (pat[i] == '*') {
			i--;
		}
		m++;
	}

	vector<vector<bool>> table(n+1, vector<bool>(m+1));
	for (int i = 0; i <= n; i++) {
		// Initialize values for empty pattern.
		table[i][0] = true;
	}
	int idx = 0;
	for (int j = 1; j <= m; j++) {
		if (j == 1 && pat[j] == '*') {
			table[0][j] = true;
			idx += 2;
		} else if (pat[idx+1] == '*'){
			table[0][j] = table[0][j-1];
			idx += 2;
		} else {
			table[0][j] = false;
			idx += 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		int idx = 0; // Index of character in the pattern.
		for (int j = 1; j <= m; j++) {
			if (idx <= pat.size()-2 && pat[idx+1] == '*') {
				if (pat[idx] != txt[i-1]) {
					table[i][j] = false;
					idx += 2;
				} else
					table[i][j] = true;
			} else if (pat[idx] == '.' || pat[idx] == txt[i-1]) {
				// Character match.
				table[i][j] = table[i-1][j-1];
				idx++;
			} else {
				// Not match.
				table[i][j] = false;
				idx++;
			}
		}
	}
	return table[n][m];
}

int main() {
	return 0;
}
