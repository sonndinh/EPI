#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Return true if a string is well-formed from characters: '{', '}', '(', ')', '[', ']'.
bool wellformed(string s) {
	stack<char> stk;
	for (int i = 0; i < s.size(); i++) {
		if (!stk.empty() && ((stk.top() == '[' && s[i] == ']') || 
							 (stk.top() == '(' && s[i] == ')') || 
							 (stk.top() == '{' && s[i] == '}'))) {
			stk.pop();
		} else {
			stk.push(s[i]);
		}
	}
	return stk.empty();
}

int main() {
	string s = "([{}()][])";
	cout << "String " << s << " is " << (wellformed(s) ? "Well-formed" : "Not Well-formed") << endl;
	cout << "Enter a string: ";
	s.clear();
	cin >> s;
	cout << "String " << s << " is " << (wellformed(s) ? "Well-formed" : "Not Well-formed") << endl;
	return 0;
}
