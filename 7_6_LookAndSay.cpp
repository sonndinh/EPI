#include <iostream>
#include <string>

using namespace std;

// Return the n-th integer in the look and say sequence.
string las(int n) {
	string str = "1";
	for (int i = 2; i <= n; i++) {
		string tmp;
		int count = 0;
		for (int j = 0; j < str.size(); j++) {
			if (j == 0 || (j > 0 && str[j] == str[j-1])) {
				count++;
			} else {
				tmp += to_string(count) + str[j-1];
				count = 1;
			}
		}
		tmp += to_string(count) + str.back();
		str = tmp;
	}
	return str;
}

int main() {
	int n;
	cout << "Enter a positive integer: ";
	cin >> n;
	cout << n << "-th look-and-say number is: " << las(n) << endl;
	return 0;
}
