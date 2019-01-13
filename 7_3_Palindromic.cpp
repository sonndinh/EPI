#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool palindromic(string s) {
	// Preprocess string: convert to lowercase, remove nonalphanumeric letters
	vector<char> arr;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			arr.push_back(s[i] - ('A' - 'a'));
		} else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
			arr.push_back(s[i]);
		}
	}

	int size = arr.size();
	for (int i = 0; i < size/2; i++) {
		if (arr[i] != arr[size - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	string s1 = "A man, a plan, a canal, Panama.";
	string s2 = "Tom Cruise cruises ship.";
	string s3 = "yay yay yay";
	cout << "\"" << s1 << "\"" << " is palindromic? " << (palindromic(s1) ? "Yes" : "No") << endl;
	cout << "\"" << s2 << "\"" << " is palindromic? " << (palindromic(s2) ? "Yes" : "No") << endl;
	cout << "\"" << s3 << "\"" << " is palindromic? " << (palindromic(s3) ? "Yes" : "No") << endl;
	return 0;
}
