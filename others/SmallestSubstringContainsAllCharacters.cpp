#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Return true if c_map is a subset of count.
bool is_satisfied(const unordered_map<char, int>& c_map, const unordered_map<char, int>& count) {
	for (const pair<char, int>& p : c_map) {
		if (count.find(p.first) == count.end() || count.at(p.first) < p.second) {
			return false;
		}
	}
	return true;
}

// Find the smallest substring of the given string that
// contains all characters in a given set of characters.
// List of input characters can contain duplicates.
string smallest_substr(string& s, vector<char>& c) {
	unordered_map<char, int> c_map;
	for (char ch : c) {
		c_map[ch]++;
	}
	// Store the appearances of the characters in the input string.
	vector<pair<int, char>> pos;
	for (int i = 0; i < s.size(); i++) {
		if (c_map.find(s[i]) != c_map.end()) {
			pos.emplace_back(make_pair(i, s[i]));
		}
	}
	
	// Not all characters found.
	if (pos.size() < c.size()) return string();
	
	int length = 0;
	string ret = "";
	unordered_map<char, int> count;	
	for (int i = 0, j = 0; i < pos.size()-c.size()+1 && j < pos.size();) {
		if (j == 0) {
			count[pos[j].second]++;
		}
		
		if (is_satisfied(c_map, count)) {
			int cur_len = pos[j].first - pos[i].first + 1;
			string cur_str = s.substr(pos[i].first, cur_len);
			if (ret.empty() || cur_len < length || (cur_len == length && cur_str.compare(ret) < 0)) {
				length = cur_len;
				ret = cur_str;
			}
			count[pos[i].second]--;
			if (count[pos[i].second] == 0) {
				count.erase(pos[i].second);
			}
            
			// Advance the pointers.
			if (i < j) {
				i++;
			} else {
				j++;
			}
		} else {
			j++;
			if (j < pos.size()) {
				count[pos[j].second]++;
			}
		}
	}
	
	return ret;        
}

int main() {
	//	string s = "qzdxbycaxtzabyk";
	//	vector<char> c{'x', 'y', 'z'};
	string s = "caae";
	vector<char> c{'c', 'a', 'e'};
	string ret = smallest_substr(s, c);
	cout << "Smallest substring of \"" << s << "\" is: " << ret << endl;
	return 0;
}
