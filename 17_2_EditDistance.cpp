#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void print_table(unsigned **len, string A, string B);

// Levenshtein distance to transform string A to string B
int min_edit_distance(string A, string B) {
	unsigned a = A.size();
	unsigned b = B.size();

	// Can optimize it further to use only 1D array for storing 
	// intermediate distances. Here we use a 2D array.
	unsigned len[b+1][a+1];
	for (unsigned i = 0; i <= a; i++) {
		len[0][i] = i;
	}

	for (unsigned i = 0; i <= b; i++) {
		len[i][0] = i;
	}

	for (unsigned i = 1; i <= b; i++) {
		for (unsigned j = 1; j <= a; j++) {
			if (A[j-1] == B[i-1]) {
				len[i][j] = len[i-1][j-1];
			} else {
				len[i][j] = 1 + min(len[i-1][j-1], min(len[i-1][j], len[i][j-1]));
			}
		}
	}

	// Print testing the table
	//	print_table(len, A, B);

	return len[b][a];
}

void print_table(unsigned **len, string A, string B) {
	for (unsigned i = 0; i <= b; i++) {
		for (unsigned j = 0; j <= a; j++) {
			cout << len[i][j] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) {
	cout << "Edit distance of \"Orchestra\" and \"Carthorse\": " << min_edit_distance("Carthorse", "Orchestra") << endl;
	return 0;
}
