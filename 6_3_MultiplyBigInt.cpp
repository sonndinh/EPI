#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_vec(vector<char> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
	}
	cout << endl;
}

// Multiply 2 big integer presented as 2 strings of decimal digits 
// and return the result also as a string.
string multiply(string A, string B) {
	int a_size = A[0] == '-'? A.size()-1 : A.size();
	int b_size = B[0] == '-'? B.size()-1 : B.size();
	int a_start = A[0] == '-'? 1 : 0;
	int b_start = B[0] == '-'? 1 : 0;

	bool negative = false;
	if ((A[0] == '-' && B[0] != '-') ||
		(A[0] != '-' && B[0] == '-')) {
		negative = true;
	}

	// Store characters of the final result
	vector<char> final(a_size + b_size, '0');
	for (int i = B.size()-1; i >= b_start; i--) {
		int offset = B.size() - 1 - i; // offset from the end of the final vector
		// Store characters of intermediate results
		vector<char> tmp(a_size + 1, '0');
		char ib = B[i] - '0';
	
		char carry = 0;
		for (int j = A.size()-1; j >= a_start; j--) {
			char ia = A[j] - '0';
			char c = ia * ib + carry; // numeric value
			tmp[j+1] = c % 10 + '0'; // convert to character
			carry = c / 10;
		}
		tmp[0] = carry + '0';
		//cout << "Tmp: "; print_vec(tmp);

		// Add intermediate result to the final result
		carry = 0;
		int idx = a_size + b_size - 1 - offset;
		int p = tmp.size() - 1;
		for (; idx >= 0; idx--, p--) {
			if (p < 0 && carry == 0) break;
			char num; // numeric value for the sum of 2 digits
			if (p >= 0) {
				num = (tmp[p] - '0') + (final[idx] - '0') + carry;
			} else {
				num = final[idx] + carry;
			}
			final[idx] = num % 10 + '0'; // convert back to character
			carry = num / 10;
		}
	}

	string ret = "";
	if (negative) {
		ret = "-";
	}

	ret += string(final.begin(), final.end());
	return ret;
}


int main(int argc, char *argv[]) {
	cout << "193707721 times -761838257287 = " << multiply("193707721", "-761838257287") << endl;
	return 0;
}
