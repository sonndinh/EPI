#include <iostream>
#include <vector>

using namespace std;

// Find intersection of 2 sorted arrays with no duplicates.
// O(m+n) solution. 
vector<int> intersect(const vector<int>& A, const vector<int>& B) {
	vector<int> ret;
	for (int i = 0, j = 0; i < A.size() && j < B.size();) {
		if (A[i] == B[j]) {
			ret.push_back(A[i]);
			i++;
			j++;
		} else if (A[i] > B[j]) {
			j++;
		} else {
			i++;
		}
	}
	return ret;
}

bool bsearch(int a, const vector<int>& B) {
	int s = 0, t = B.size() - 1;
	while (s <= t) {
		int m = s + (t-s)/2;
		if (B[m] == a) return true;
		if (B[m] < a) {
			s = m + 1;
		} else {
			t = m - 1;
		}
	}
	return false;
}

// Use binary search to find a matching entry in the longer array.
// Good when 2 arrays have very different lengths, m << n.
// Complexity O(mlgn).
vector<int> intersect2(const vector<int>& A, const vector<int>& B) {
	vector<int> ret;
	auto& source = A.size() < B.size() ? A : B;
	auto& target = A.size() < B.size() ? B : A;

	for (int s : source) {
		if (bsearch(s, target))
			ret.push_back(s);
	}
	return ret;
}

int main() {
	vector<int> A{2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> B{0, 1, 4, 6, 7, 9, 11, 12};
	cout << "A:";
	for (int a : A) {
		cout << " " << a;
	}
	cout << "\nB:";
	for (int b : B) {
		cout << " " << b;
	}
	cout << "\nIntersection:";
	vector<int> C = intersect2(A, B);
	for (int c : C) {
		cout << " " << c;
	}
	cout << endl;
	
	return 0;
}
