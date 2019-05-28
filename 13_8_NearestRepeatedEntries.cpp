#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

// Find the distance between a pair of closest, equal entries.
pair<string, int> nearest_entries(const vector<string>& A) {
	// Each pair contains the minimum distance of the corresponding
	// string and the position of its last occurrence found so far.
	unordered_map<string, pair<int, int>> dist;
	string min_str;
	int min_dist = A.size(); // Minimum distance.

	for (int i = 0; i < A.size(); ++i) {
		const string& s = A[i];
		if (dist.count(s) == 0) {
			dist.emplace(s, make_pair(A.size(), i));
		} else {
			int prev_pos = dist[s].second;
			int prev_dist = dist[s].first;
			if (i - prev_pos < prev_dist) {
				dist[s].first = i - prev_pos;
				if (dist[s].first < min_dist) {
					min_dist = dist[s].first;
					min_str = s;
				}
			}
			dist[s].second = i;
		}
	}

	return {min_str, min_dist};
}

int main() {
	vector<string> A{"All", "work", "and", "no", "play", "makes", "for", "no", "work", "no", "fun", "and", "no", "results"};
	auto ret = nearest_entries(A);
	cout << "Input: ";
	for (string& s : A) {
		cout << s << " ";
	}
	cout << endl;
	cout << "Closest entries: " << ret.first << ", distance: " << ret.second << endl;
	return 0;
}
