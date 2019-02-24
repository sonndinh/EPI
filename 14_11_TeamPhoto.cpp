#include <iostream>
#include <vector>

using namespace std;

// 2 teams have the same number of players.
// Return whether can take a photo.
bool photo(vector<int>& A, vector<int>& B) {
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	bool a_back;
	if (A[0] > B[0]) a_back = true;
	else if (A[0] < B[0]) a_back = false;
	else return false;
	
	for (int i = 1; i < A.size(); i++) {
		if ((A[i] <= B[i] && a_back) ||
			(B[i] <= A[i] && !a_back))
			return false;
	}
	return true;
}

int main() {
	vector<int> A{1, 3, 5, 7, 9, 15};
	vector<int> B{0, 2, 4, 6, 10, 11};
	cout << "A[";
	for (int a : A) {
		cout << " " << a;
	}
	cout << "]\nB[";
	for (int b: B) {
		cout << " " << b;
	}
	cout << "] ===> " << (photo(A, B)? "Possible" : "Impossible") << endl;

	return 0;
}
