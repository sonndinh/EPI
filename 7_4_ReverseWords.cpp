#include <iostream>
#include <string>

using namespace std;

string reverse(string s) {
	int old_size = s.size();
	int size = s.size();
	int start = 0;
	for (int i = s.size()-1; i >= 0; i--) {
		if (s[i] == ' ') {
			size += i + 1;
			start = i + 1;
			break;
		}
	}

	s.resize(size);
	int p = start - 1;
	int q = p;
	for (int i = old_size, j = start - 1; i < s.size(); j--) {
		if (s[j] == ' ') s[i++] = ' ';
		if (s[j] != ' ' && s[j+1] == ' ') q = j;
		if ((s[j] != ' ' && s[j-1] == ' ') || j == 0)  {
			p = j;
			for (int k = p; k <= q; k++, i++) {
				s[i] = s[k];
			}
		}
	}

	return s.substr(start);
}

int main() {
	cout << "Reverse: \"Alice likes Bob\" ==> " << reverse("Alice likes Bob") << endl;
	cout << "Reverse: \"  Alice likes Bob\" ==> " << reverse("  Alice likes Bob") << endl;
	cout << "Reverse: \"Alice\" ==> " << reverse("Alice") << endl;
    return 0;
}
