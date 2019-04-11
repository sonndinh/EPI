#include <iostream>
#include <string>
using namespace std;

bool helper(const string& t, int i, const string& s1, int i1, const string& s2, int i2) {
	if (i == t.size() || i1 == s1.size() || i2 == s2.size())
		return true;
		
	if (t[i] == s1[i1] && t[i] == s2[i2])
		return helper(t, i+1, s1, i1+1, s2, i2) || helper(t, i+1, s1, i1, s2, i2+1);
	else if (t[i] == s1[i1])
		return helper(t, i+1, s1, i1+1, s2, i2);
	else if (t[i] == s2[i2])
		return helper(t, i+1, s1, i1, s2, i2+1);
	else
		return false;
}

// Return whether string t is formed by interleaving s1 and s2.
bool is_interleaved(const string& t, const string& s1, const string& s2) {
	if (t.size() != s1.size() + s2.size())
		return false;

	return helper(t, 0, s1, 0, s2, 0);
}

int main() {
	string t = "gattaca", s1 = "gtaa", s2 = "atc";
	cout << (is_interleaved(t, s1, s2)? "Is an interleaving" : "Is NOT an interleaving") << endl;
	return 0;
}
