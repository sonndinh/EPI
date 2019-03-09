#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void helper(string& number, unordered_map<char, string>& keypad, int k, vector<string>& list, string& curr) {
	if (k == number.size()) {
		// All digits have been converted to characters, just add to the list and return.
		list.push_back(curr);
		return;
	}

	// The current digit being considered.
	char d = number[k];
	if (keypad[d].empty()) {
		curr += d;
		helper(number, keypad, k+1, list, curr);
		curr.erase(curr.size()-1);
	} else {
		for (char c : keypad[d]) {
			curr += c;
			helper(number, keypad, k+1, list, curr);
			curr.erase(curr.size()-1);
		}
	}
}

// Return all mnemonics for a given phone number.
// Keypad maps from each digit to a list of characters.
vector<string> mnemonics(string number, unordered_map<char, string> keypad) {
	vector<string> ret;
	string curr;
	helper(number, keypad, 0, ret, curr);
	return ret;
}

int main() {
	unordered_map<char, string> keypad = {{'0', ""}, {'1', ""}, {'2', "ABC"}, {'3', "DEF"}, {'4', "GHI"},
										  {'5', "JKL"}, {'6', "MNO"}, {'7', "PQRS"}, {'8', "TUV"}, {'9', "WXYZ"}};
	string number = "314";
	vector<string> mne = mnemonics(number, keypad);
	cout << "List of mnemonics: ";
	for (string s : mne) {
		cout << s << " ";
	}
	cout << endl;
	return 0;
}
