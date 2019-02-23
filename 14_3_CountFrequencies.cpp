#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <cstdlib>

using namespace std;

// Complexity is not O(n) since map is implemented as a tree.
map<char, int> count(string s) {
	map<char, int> m;
	for (int i = 0; i < s.size(); i++) {
		if ((char)s[i] != ' ')
			m[s[i]]++;
	}
	return m;
}

int partition(string& s, int p, int r) {
	srand(time(NULL));
	int x = rand() % (r - p + 1) + p;
	swap(s[x], s[r]);
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (s[j] < s[r]) {
			swap(s[++i], s[j]);
		}
	}
	swap(s[++i], s[r]);
	return i;
}

void qsort(string& s, int p, int r) {
	if (p < r) {
		int q = partition(s, p, r);
		qsort(s, p, q-1);
		qsort(s, q+1, r);
	}
}

vector<pair<char, int>> count2(string s) {
	qsort(s, 0, s.size()-1);
	vector<pair<char, int>> ret;
	char c = s[0];
	int freq = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == c) {
			freq++;
		} else {
			ret.push_back(make_pair(c, freq));
			c = s[i];
			freq = 1;
		}
	}
	return ret;
}

int main() {
	string s = "Hello world!";
	cout << "String: " << s << ". Frequencies:";
	//	map<char, int> ret = count(s);
	vector<pair<char, int>> ret = count2(s);
	for (auto& p : ret) {
		cout << " (" << p.first << "," << p.second << ")";
	}
	cout << endl;
	return 0;
}
