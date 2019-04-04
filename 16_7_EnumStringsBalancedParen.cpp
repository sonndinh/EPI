#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> helper(int l, int k) {
	if (l == 0)
		return {""};

	vector<string> ret;
	vector<string> ret1 = helper(l-1, k);
	for (string& s : ret1) {
		s = "(" + s + ")";
	}
	ret = ret1;

	for (int i = 1; i < l; i++) {
		vector<string> concat1 = helper(i, k);
		vector<string> concat2 = helper(l-i, k);
		
		for (string s1 : concat1) {
			for (string s2 : concat2) {
				ret.push_back(s1 + s2);
			}
		}
	}

	return ret;
}

// Return all strings consist of k pairs matched parens.
vector<string> matched_parens(int k) {
	vector<string> ret = helper(k, k);
	return ret;
}

// Parameter @left_parens tracks the number of unmatched left parentheses.
void helper2(vector<string>& ret, string tmp, int remain, int left_parens) {
	if (remain == 0) {
		ret.push_back(tmp);
		return;
	}
	
	if (left_parens < remain) {
		// Can add a left paren.
		helper2(ret, tmp + "(", remain-1, left_parens+1);
	}

	if (left_parens > 0) {
		// Can add a right paren.
		helper2(ret, tmp + ")", remain-1, left_parens-1);
	}
}

vector<string> matched_parens2(int k) {
	vector<string> ret;
	helper2(ret, string(), 2*k, 0);
	return ret;
}

int main() {
	int k = 4;
	vector<string> ret = matched_parens2(k);
	for (string s : ret) {
		cout << s << "  ";
	}
	cout << endl;
	return 0;
}
