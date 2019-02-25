#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool constructible(const string& letter, const string& magazine) {
	if (letter.size() > magazine.size()) return false;
	unordered_map<char, int> counts;

	for (const char& c : letter) {
		counts[c]++;
	}
	
	for (const char& c : magazine) {
		if (counts.find(c) != counts.cend()) {
			counts[c]--;
			if (counts[c] == 0)
				counts.erase(c);
			if (counts.empty())
				return true;
		}
	}
	return false;
	/*
	for (int i = 0; i < magazine.size(); i++) {
		counts[magazine[i]]++;
	}
	for (int i = 0; i < letter.size(); i++) {
		counts[letter[i]]--;
		if (counts[letter[i]] < 0)
			return false;
	}
	return true;
	*/
}

int main() {
	string letter = "hahahaha";
	string magazine = "hah hah hah hah";
	cout << "Constructible? " << (constructible(letter, magazine)? "Yes" : "No") << endl;
	return 0;
}
