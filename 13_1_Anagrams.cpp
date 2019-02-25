#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<string>> group(const vector<string>& dict) {
	vector<vector<string>> ret;
	unordered_map<string, vector<string>> groups;
	
	for (const string& s : dict) {
		string key(s);
		sort(key.begin(), key.end());
		groups[key].emplace_back(s);
	}

	for (const pair<string, vector<string>>& p : groups) {
		if (p.second.size() > 1) {
			ret.emplace_back(p.second);
		}
	}
	return ret;
}

int main() {
	vector<string> dict{"debitcard", "elvis", "silent", "badcredit", "lives", "freedom", "listen", "levis"};
	vector<vector<string>> groups = group(dict);
	for (const vector<string>& g : groups) {
		cout << "Group:";
		for (const string s : g) {
			cout << " " << s;
		}
		cout << endl;
	}
	return 0;
}
