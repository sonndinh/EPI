#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Return true if a string is palindromic.
bool is_palin(string s) {
	int n = s.size();
	for (int i = 0; i < n/2; i++) {
		if (s[i] != s[n - 1 - i])
			return false;
	}
	return true;
}

void decompose_helper(vector<vector<string>>& decoms, vector<string>& curr_set, string s) {
	if (s == "") {
		decoms.push_back(curr_set);
		return;
	}
	
	for (int i = 0; i < s.size(); i++) {
		string tmp = s.substr(0, i+1);
		if (is_palin(tmp)) {
			curr_set.push_back(tmp);
			decompose_helper(decoms, curr_set, s.substr(i+1));
			curr_set.pop_back();
		}
	}
}

// Compute all palindromic decompositions of a string.
vector<vector<string>> decompose(string s) {
	vector<vector<string>> ret;
	vector<string> curr_set;
	decompose_helper(ret, curr_set, s);
	return ret;
}

int main() {
	string s = "020441881";
	auto ret = decompose(s);
	for (vector<string>& vec : ret) {
		cout << "(";
		for (int i = 0; i < vec.size(); i++) {
			if (i < vec.size()-1)
				cout << vec[i] << ", ";
			else
				cout << vec[i];
		}
		cout << ")" << endl;
	}

	return 0;
}
