#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>

using namespace std;

tuple<int, int, int> biggest_range(const vector<int>& A) {
	if (A.size() == 0) return {0, 0, 0};
	// Map from each number in the array to its lower end.
	unordered_map<int, tuple<int, bool, bool>> entries;
	for (int i = 0; i < A.size(); i++) {
		int a = A[i];
		if (entries.find(a) == entries.cend()) {
			entries[a] = make_tuple(1, false, false);
		} else {
			get<0>(entries[a])++;
		}
	}

	// Propagate the map.
	for (auto iter = entries.begin(); iter != entries.end(); iter++) {
		int key = iter->first;
		tuple<int, bool, bool>& val = iter->second;
		if (entries.find(key-1) != entries.end())
			get<1>(val) = true;
		if (entries.find(key+1) != entries.end())
			get<2>(val) = true;
	}
	
	int max_lower, max_upper, max_len = 0;
	int lower, upper, len;
	while (!entries.empty()) {
		auto it = entries.begin();
		int key = it->first;
		tuple<int, bool, bool>& val = it->second;
		len = 0;
		len += get<0>(val);
		lower = key, upper = key;
		
		auto prev = it;
		bool has_prev = get<1>(prev->second);
		int curr_key = key;
		while (has_prev) {
			prev = entries.find(--curr_key);
			len += get<0>(prev->second);
			lower = curr_key;
			has_prev = get<1>(prev->second);
			entries.erase(prev);
		}
		
		auto next = it;
		bool has_next = get<2>(next->second);
		curr_key = key;
		while(has_next) {
			next = entries.find(++curr_key);
			len += get<0>(next->second);
			upper = curr_key;
			has_next = get<2>(next->second);
			entries.erase(next);
		}
		entries.erase(it);
		if (len > max_len) {
			max_len = len;
			max_lower = lower;
			max_upper = upper;
		}
	}

	return {max_len, max_lower, max_upper};
}

int main() {
	//	vector<int> A{3,-2,7,9,8,1,2,0,-1,5,8};
	vector<int> A{5,6,7,8,8,9,1,3,15};
	tuple<int, int, int> t = biggest_range(A);
	cout << "Length of longest range: " << get<0>(t) << ". In range: [" << get<1>(t) << "," << get<2>(t) << "]" << endl;
	return 0;
}
