#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <unordered_map>
using namespace std;

// Hash function for a set.
struct HashAttributes {
	size_t operator() (const set<string>& input) const {
		// Concatenate the strings using underscores as delimiters.
		string concat;
		for (const string& s: input) {
			if (concat == "") {
				concat += s;
			} else {
				concat += "_" + s;
			}
		}

		return hash<string>{}(concat);
	}
};

// Pair users with the same sets of attributes.
// Input is an array of users with unique IDs and their set of attributes.
// Return an array of pairs of users.
vector<pair<int, int>> pair_users(const vector<pair<int, set<string>>>& users) {
	vector<pair<int, int>> result;
	
	// Each entry maps from a set of attributes to a unpaired user ID with those attributes.
	unordered_map<set<string>, int, HashAttributes> unpaired;
	
	for (auto& p : users) {
		int id = p.first;
		const set<string>& attr = p.second;

		auto iter = unpaired.find(attr);
		if (iter != unpaired.end()) {
			// Found a matched user. Pair them.
			result.emplace_back(id, iter->second);
			unpaired.erase(attr);
		} else {
			// Not found. Add this user to the list of unpaired users.
			unpaired.emplace(attr, id);
		}
	}

	return result;
}

int main() {
	return 0;
}
