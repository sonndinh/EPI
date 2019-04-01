#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Return a word that repeats more than half of a given stream.
// Only allow a single pass through the stream, and constant memory.
string major_elem(const vector<string>& A) {
	string major;
	int count = 0;
	for (int i = 0; i < A.size(); i++) {
		if (count == 0) {
			major = A[i];
			count++;
		} else if (major == A[i]) {
			count++;
		} else {
			count--;
		}
	}
	return major;
}

int main() {
	vector<string> A{"w", "c", "x", "x", "w", "w", "w", "b", "d", "w", "w"};
	cout << "Major element: " << major_elem(A) << endl;
	return 0;
}
