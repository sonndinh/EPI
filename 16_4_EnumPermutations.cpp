#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Print all permutations of an array.
void permu(vector<vector<int>>& permutations, vector<int> curr, vector<int> remain) {
	if (remain.size() == 0) {
		permutations.push_back(curr);
		return;
	}

	vector<int> tmp(remain);
	for (int k : remain) {
		vector<int>::iterator it = find(tmp.begin(), tmp.end(), k);
		tmp.erase(it);
		curr.push_back(k);
		permu(permutations, curr, tmp);
		curr.pop_back();
		tmp.push_back(k);
	}	  
}

void print_permu(const vector<vector<int>>& sols, int size) {
	for (const vector<int>& sol : sols) {
		cout << "[";
		int count = 0;
		for (const int& i : sol) {
			count++;
			cout << i << (count == size? "" : ",");
		}
		cout << "], ";
	}
	cout << endl;
}

int main() {
	vector<int> arr{2, 3, 5};
	vector<vector<int>> permutations;
	vector<int> curr;
	permu(permutations, curr, arr);
	print_permu(permutations, arr.size());
	return 0;
}
