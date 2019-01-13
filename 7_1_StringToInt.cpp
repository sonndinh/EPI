#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int convert(string s) {
	bool negative = false;
	int start = 0;
	if (s[0] == '-') {
		negative = true;
		start = 1;
	}

	int num = 0;
	for (int i = s.size()-1; i >= start; i--) {
		int tmp = (s[i] - '0') * (int)pow(10, s.size() - 1 - i);
		num += tmp;
	}

	if (negative)
		return -num;
	return num;
}

int main(int argc, char *argv[]) {
	cout << "String \"-000001234567\" to integer: " << convert("-1234567") << endl;
	return 0;
}
