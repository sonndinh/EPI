#include <iostream>
#include <vector>

using namespace std;

// Return the number of distinct sequences of plays that yield a score s.
int count_permutations(unsigned s, vector<unsigned> &scores) {
	vector<unsigned> ways(s+1, 0);
	ways[0] = 1;

	for (unsigned i = 1; i <= s; i++) {
		for (unsigned score : scores) {
			if (i >= score) {
				ways[i] += ways[i - score];
			}
		}
	}

	return ways[s];
}

int count_combinations(unsigned s, vector<unsigned> &scores) {
	vector<unsigned> combinations(s+1, 0);
	combinations[0] = 1;

	for (unsigned score : scores) {
		for (unsigned i = score; i <= s; i++) {
			combinations[i] += combinations[i - score];
		}
	}

	return combinations[s];
}

int main(int argc, char *argv[]) {
	unsigned arr[] = {2, 3, 7};
	vector<unsigned> scores(arr, arr + sizeof(arr)/sizeof(unsigned));
	cout << "s = 2 --- Permutations: " << count_permutations(2, scores) 
		 << ". Combinations: " << count_combinations(2, scores) << endl;

	cout << "s = 4 --- Permutations: " << count_permutations(4, scores) 
		 << ". Combinations: " << count_combinations(4, scores) << endl;

	cout << "s = 6 --- Permutations: " << count_permutations(6, scores) 
		 << ". Combinations: " << count_combinations(6, scores) << endl;

	cout << "s = 7 --- Permutations: " << count_permutations(7, scores) 
		 << ". Combinations: " << count_combinations(7, scores) << endl;

	cout << "s = 9 --- Permutations: " << count_permutations(9, scores) 
		 << ". Combinations: " << count_combinations(9, scores) << endl;

	cout << "s = 11 --- Permutations: " << count_permutations(11, scores) 
		 << ". Combinations: " << count_combinations(11, scores) << endl;

	cout << "s = 1234 --- Permutations: " << count_permutations(1234, scores) 
		 << ". Combinations: " << count_combinations(1234, scores) << endl;

	return 0;
}
