#include <iostream>
#include <unordered_map>
using namespace std;

// Convert a valid Roman number to a decimal number, e.g., LIX to 59.
int to_decimal(const string& A) {
	unordered_map<char, int> letter_to_num{{'I', 1}, {'V', 5} , {'X', 10}, {'L', 50},
										   {'C', 100}, {'D', 500}, {'M', 1000}};
	int val = 0;
	for (int i = 0; i < A.size(); i++) {
		if (i > 0 && letter_to_num[A[i-1]] < letter_to_num[A[i]]) {
			val -= letter_to_num[A[i-1]]; // Subtract if it is an exception.
			val += letter_to_num[A[i]] - letter_to_num[A[i-1]];
		} else {
			// Proactively adding the value of the current letter.
			val += letter_to_num[A[i]];;
		}
	}
	
	return val;
}

int main() {
	string A = "LIX";
	string B = "LVIIII";
	string C = "IC";
	cout << A << " ==> " << to_decimal(A) << endl;
	cout << B << " ==> " << to_decimal(B) << endl;
	cout << C << " ==> " << to_decimal(C) << endl;
	return 0;
}
