#include <iostream>

using namespace std;

unsigned search_root(unsigned x) {
	if (x == 0 || x == 1) return x;

	unsigned r = x/2;
	unsigned start = 1;
	unsigned end = x;
	while ((r+1)*(r+1) <= x || r*r >= x) {
		if ((r+1)*(r+1) == x) return r+1;
		if (r*r == x) return r;

		if (r*r > x) {
			end = r-1;
		} else if ((r+1)*(r+1) < x) {
			start = r+2;
		}
		r = (start + end)/2;
	}

	return r;
}

int main() {
	unsigned x = 400;
	cout << "Square root of " << x << " is: " << search_root(x) << endl;
	return 0;
}
