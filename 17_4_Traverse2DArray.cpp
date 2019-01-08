#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Count the number of ways to go from the top-left to the bottom-right of 
// a matrix of size n x m. 
unsigned count_ways(unsigned n, unsigned m) {
	unsigned min = n < m? n : m;
	unsigned max = n < m? m : n;
	vector<unsigned> arr(min);

	for (unsigned i = 0; i < min; i++) {
		arr[i] = 1;
	}

	for (unsigned j = 1; j < max; j++) {
		for (unsigned i = 1; i < min; i++) {
			arr[i] = arr[i-1] + arr[i];
		}
	}

	return arr[min-1];
}

// Count the number of ways from top-left to bottom-right 
// of a matrix of boolean in the presence of obstacles.
unsigned count_ways(unsigned n, unsigned m, const vector<vector<bool> >& B) {
	if (B[0][0] == true || B[n-1][m-1] == true) {
		// No way if the top-left or bottom-right is an obstacle.
		return 0;
	}
	vector<vector<int> > arr(n, vector<int>(m, 0));

	// Set values for the first row
	for (int j = 0; j < m; j++) {
		if (B[0][j] == true) {
			break;
		}
		arr[0][j] = 1;
	}
	
	// Set values for the first column
	for (int i = 0; i < n; i++) {
		if (B[i][0] == true) {
			break;
		}
		arr[i][0] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (B[i][j] == false) {
				arr[i][j] = arr[i-1][j] + arr[i][j-1];
			}
		}
	}

	return arr[n-1][m-1];
}

int main(int argc, char *argv[]) {
	cout << "Array 5x5: " << count_ways(5, 5) << endl;
	return 0;
}
