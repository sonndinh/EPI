#include <iostream>
#include <limits>

using namespace std;

enum Order {SMALLER, EQUAL, GREATER};

Order compare(double a, double b) {
	double diff = a - b;
	if (diff < -numeric_limits<double>::epsilon())
		return SMALLER;
	else if (diff > numeric_limits<double>::epsilon())
		return GREATER;
	else
		return EQUAL;
}

double root(double x) {
	double left, right;
	if (x < 1.0) {
		left = x;
		right = 1.0;
	} else {
		left = 1.0;
		right = x;
	}
	
	while (compare(left, right) == SMALLER) {
		double mid = (left + right)/2;
		double square = mid * mid;
		if (compare(square, x) == EQUAL) {
			return mid;
		} else if (compare(square, x) == GREATER) {
			right = mid - numeric_limits<double>::epsilon();
		} else {
			left = mid + numeric_limits<double>::epsilon();
		}
	}
	return right;
}

int main() {
	double x;
	cin >> x;
	cout << "Square root of " << x << " : " << root(x) << endl;
	return 0;
}
