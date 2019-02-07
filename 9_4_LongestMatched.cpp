#include <iostream>
#include <stack>
#include <utility>

using namespace std;

// Return the length of the longest matched substring.
int match(string s) {
	stack<pair<char, int>> stk;
	for (int i = 0; i < s.size(); i++) {
		if (!stk.empty() && stk.top().first == '(' && s[i] == ')') {
			stk.pop();
		} else {
			stk.push(make_pair(s[i], i));
		}
	}
	
	int max = 0;
	int curr = s.size();
	while (!stk.empty()) {
		int len = curr - stk.top().second - 1;
		if (max < len) {
			max = len;
		}
		curr = stk.top().second;
		stk.pop();
	}
	return max;
}

int match2(string s) {
	// Don't need to use pair. Store indices of the parens instead.
	stack<int> stk;
	int max = 0;
	for (int i = 0; i < s.size(); i++) {
		if (!stk.empty() && s[stk.top()] == '(' && s[i] == ')') {
			stk.pop();
			int len = stk.empty()? i + 1 : i - stk.top();
			if (max < len)
				max = len;
		} else {
			stk.push(i);
		}
	}
	return max;
}

int main() {
	string s = "(()(()())(()()";
	cout << "String " << s << " ==> Max matched length: " << match2(s) << endl;
	cout << "Input: ";
	s.clear();
	cin >> s;
	cout << "String " << s << " ==> Max matched length: " << match2(s) << endl;
	return 0;
}
