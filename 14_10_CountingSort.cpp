#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

struct Person {
	int key;
	string name;
};

// Sort so that equal elements appear close together.
void counting_sort(vector<Person>& A) {
	// Count the number of times each key occurs.
	unordered_map<int, int> count;
	int max = numeric_limits<int>::min();
	int min = numeric_limits<int>::max();
	for (int i = 0; i < A.size(); i++) {
		int k = A[i].key;
		count[k]++;
		if (max < k)
			max = k;
		if (min > k)
			min = k;
	}

	// The number of entries with smaller keys.
	int tmp = 0;
	for (int k = min; k <= max; k++) {
		if (count.find(k) != count.end()) {
			count[k] += tmp;
			tmp = count[k];
		}
	}

	vector<Person> B(A.size());
	for (int i = 0; i < A.size(); i++) {
		int k = A[i].key;
		int idx = --count[k];
		B[idx] = A[i];
	}

	A = B;
}

int main() {
	vector<Person> A{{10,""}, {5,""}, {3,""}, {7,""}, {6,""}, {10,""}, {11,""}, {13,""}, {2,""}, {5,""}, {3,""}, {7,""}, {13,""}};
	counting_sort(A);
	cout << "Output:";
	for (auto& e : A) {
		cout << " " << e.key;
	}
	cout << endl;

	return 0;
}
