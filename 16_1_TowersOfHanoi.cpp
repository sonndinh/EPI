#include <iostream>

using namespace std;

void towers(int n, int source, int target, int inter) {
	if (n == 2) { // Base case.
		cout << "Ring 1 from peg " << source << " to peg " << inter << endl;
		cout << "Ring 2 from peg " << source << " to peg " << target << endl;
		cout << "Ring 1 from peg " << inter << " to peg " << target << endl;
		return;
	}

	// Move the top (n-1) rings to the intermediate peg.
	towers(n-1, source, inter, target);
	// Move the nth rings to the target peg.
	cout << "Ring " << n << " from peg " << source << " to peg " << target << endl;
	// Then move (n-1) rings from the intermediate peg to the target peg.
	towers(n-1, inter, target, source);
}

int main() {
	towers(4, 1, 2, 3);
	return 0;
}
