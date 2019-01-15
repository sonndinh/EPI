#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int string_to_int(string s) {
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

string int_to_string(int x) {
	string sign = x < 0 ? "-" : "";
	int abs = x < 0 ? -x : x;

	vector<char> str;
	while (abs > 0) {
		str.push_back((abs % 10) + '0');
		abs = abs / 10;
	}

	return (sign + string(str.rbegin(), str.rend()));
}

int main(int argc, char *argv[]) {
	cout << "String \"-000001234567\" to integer: " << string_to_int("-1234567") << endl;
	cout << "Integer -987654321 to string: " << int_to_string(-987654321) << endl;
	return 0;
}
