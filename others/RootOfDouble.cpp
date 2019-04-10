#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

double epsilon = numeric_limits<double>::epsilon();

// Compute the n-th root of a number. Assuming non-negative numbers.
double root(double x, int n) {
	// Special cases.
	if (x == 1.0 || x == 0.0) return x;

	double left, right;
	if (x < 1.0) {
		left = x;
		right = 1.0;
	} else {
		left = 1.0;
		right = x;
	}
	
	while (right - left > epsilon) {
		double mid = left + (right - left)/2;
		double estimate = pow(mid, n);
		
		if (estimate - x <= epsilon && estimate - x >= -epsilon) {
			return mid;
		} else if (estimate - x > epsilon) {
			right = mid;
		} else {
			left = mid;
		}
	}
	
	return right;
}

int main() {
	int n = 3;
	double x = 0.8;
	cout << n << "-th root of " << x << ": " << root(x, n) << endl;
	return 0;
}
