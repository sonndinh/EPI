#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Return a pair of pages with highest affinity.
// Each pair in the input is a pair of page and user that views that page.
pair<string, string> pair_with_highest_affinity(const vector<pair<string, string>>& logs) {
	unordered_map<string, unordered_set<string>> page_to_users;
	for (auto& p : logs) {
		page_to_users[p.first].insert(p.second);
	}

	// Go through all pairs of pages. Keep track of which pair has highest affinity.
	int max_affinity = 0;
	pair<string, string> result;

	unordered_map<string, unordered_set<string>>::const_iterator i, j;
	for (i = page_to_users.cbegin(); i != page_to_users.cend(); ++i) {
		j = i;
		++j;
		for (; j != page_to_users.cend(); ++j) {
			const unordered_set<string>& users_i = i->second;
			const unordered_set<string>& users_j = j->second;
			int affinity = 0;
			for (const string& user : users_i) {
				if (users_j.count(user) > 0) ++affinity;
			}

			// Update the maximum affinity.
			if (affinity > max_affinity) {
				max_affinity = affinity;
				result = {i->first, j->first};
			}
		}
	}

	return result;
}

int main() {
	vector<pair<string, string>> logs{{"yahoo", "A"}, {"google", "A"}, {"twitter", "B"}, {"google", "C"},
									  {"google", "C"}, {"google", "B"}, {"twitter", "C"}, {"twitter", "A"}, {"yahoo", "C"}};
	auto ret = pair_with_highest_affinity(logs);
	cout << "Pages with highest affinity: " << ret.first << ", " << ret.second << endl;
	return 0;
}
