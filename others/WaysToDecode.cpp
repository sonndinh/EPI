#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Letters a-z are encoded using numbers 1-26.
// Given an encoded message containing digits, return the number of ways to decode it.
int decode(const string& s) {
	int n = s.size();
	vector<int> dp(n+1);
	dp[n] = 1; dp[n-1] = 1;

	for (int i = n-2; i >= 0; i--) {
		// Compute the value of the 2-digit number starting at index i.
		int a = (s[i] - '0')*10 + (s[i+1] - '0');
		if (a > 26) {
			dp[i] = dp[i+1];
		} else {
			dp[i] = dp[i+1] + dp[i+2];
		}
	}
	return dp[0];
}

int main() {
	string s = "23", s2 = "1261", s3 = "2352112", s4 = "123";
	cout << "Number of ways to decode " << s << ": " << decode(s) << endl;
	cout << "Number of ways to decode " << s2 << ": " << decode(s2) << endl;
	cout << "Number of ways to decode " << s3 << ": " << decode(s3) << endl;
	cout << "Number of ways to decode " << s4 << ": " << decode(s4) << endl;
	return 0;
}
