#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

struct Compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
	}
};

// Minimize the total waiting time of n queries.
// Input is a list of n requests with their service times.
// Return total waiting time.
int minimize(vector<pair<int, int>>& t) {
	sort(t.begin(), t.end(), Compare());
	int total = 0, curr = 0;
	for (int i = 1; i < t.size(); i++) {
		curr += t[i-1].second;
		total += curr;
	}
	return total;
}

int main() {
	vector<pair<int, int>> requests{{1, 10}, {2, 4}, {3, 7}, {4, 1}, {5, 12}, {6, 5}};
	int total = minimize(requests);
	cout << "Minimum total waiting time: " << total << endl;
	cout << "In request order: ";
	for (const pair<int, int>& p : requests) {
		cout << p.first << " ";
	}
	cout << endl;
	return 0;
}
