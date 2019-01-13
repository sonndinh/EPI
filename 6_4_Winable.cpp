#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool winable(vector<int> A) {
	int reach = 0;
	// For each position, calculate the largest index that can 
	// be reached from all the positions examined so far.
	for (int i = 0; i <= reach && reach < A.size()-1; i++) {
		reach = max(reach, i + A[i]);
	}

	return (reach >= A.size()-1);
}

int main(int argc, char *argv[]) {
	vector<int> A{3, 3, 1, 0, 2, 0, 1};
	cout << "A[3, 3, 1, 0, 2, 0, 1] ==> " << (winable(A)==true? "reachable" : "unreachable") << endl;
	return 0;
}
