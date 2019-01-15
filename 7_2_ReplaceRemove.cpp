#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Replace all 'a' characters with "dd"; remove all 'b' characters.
string replace_remove(string s) {
	vector<char> final;
	vector<int> indices(s.size(), -1);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a') {
			final.push_back('d');
			final.push_back('d');
		} else if (s[i] != 'b') {
			final.push_back(s[i]);
		}
	}

	return string(final.begin(), final.end());
}

string replace_remove_inplace(string s) {
	int a_count = 0;
	int write_idx = 0;
	int size = s.size();
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != 'b') {
			s[write_idx] = s[i];
			write_idx++;
		} else {
			size--;
		}
		if (s[i] == 'a') {
			a_count++;
		}
	}

	s.resize(size + a_count);
	int curr_idx = size - 1;
	for (int i = s.size()-1; i >= 0;) {
		if (s[curr_idx] == 'a') {
			s[i] = 'd';
			s[i-1] = 'd';
			i -= 2;
		} else {
			s[i] = s[curr_idx];
			i--;
		}
		curr_idx--;
	}
	
	return s;
}

int main(int argc, char *argv[]) {
	cout << "Input: \"acdbccccbadd\" ==> Output: " << replace_remove_inplace("acdbccccbadd") << endl;
	return 0;
}
