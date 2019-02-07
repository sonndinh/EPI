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

int main() {
	string s = "(()(()())(()()";
	cout << "String " << s << " ==> Max matched length: " << match(s) << endl;
	return 0;
}
