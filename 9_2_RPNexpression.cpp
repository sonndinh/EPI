#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

// Receive a Reverse Polish Notation expression and return its evaluated value.
// E.g., Input: "2,3,+,2,*" -> Output: 10.
// Assuming the input string is a valid RPN expression.
int eval(string s) {
	stack<int> stk;
	string num;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			int a = stk.top();
			stk.pop();
			int b = stk.top();
			stk.pop();
			
			switch(s[i]) {
			case '+':
				stk.push(a+b);
				break;
			case '-':
				stk.push(a-b);
				break;
			case '*':
				stk.push(a*b);
				break;
			case '/':
				stk.push(a/b);
				break;
			default:
				break;
			}
		} else if (s[i] >= '0' && s[i] <= '9') {
			num += s[i];
		} else if (s[i] == ',' && !num.empty()) {
			// Convert string to integer.
			int n = 0;
			for (int i = num.size()-1; i >= 0; i--) {
				int digit = num[i] - '0';
				n += digit * pow(10, num.size()-1-i);
			}
			stk.push(n);
			num.clear();
		}
	}
	return stk.top();
}

int main() {
	string rpn = "2,3,+,2,*";
	cout << "Input: " << rpn << ". Output: " << eval(rpn) << endl;
	cout << "Enter a valid RPN: ";
	rpn.clear();
	cin >> rpn;
	cout << "Output: " << eval(rpn) << endl;
	return 0;
}
