#include <iostream>
#include <set>

using namespace std;

void print_subset(set<int>& subset) {
	int count = 0;
	cout << "{";
	for (auto& i : subset) {
		count++;
		cout << i << (count == subset.size()? "" : ",");
	}
	cout << "}\n";
}

// Print the power set of a set of distinct elements.
void power_set(const set<int>& S, set<int>::iterator it, set<int>& subset) {
	if (it == S.end()) {
		print_subset(subset);
	} else {
		int elem = *it;
		// Skip this element.
		power_set(S, ++it, subset);
		
		// Or include it.
		subset.insert(elem);
		power_set(S, it, subset);
		subset.erase(subset.find(elem));
	}
}

int main() {
	set<int> S{1, 2, 3, 4};
	set<int> subset;
	power_set(S, S.begin(), subset);
	return 0;
}
