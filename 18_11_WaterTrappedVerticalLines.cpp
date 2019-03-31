#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Return pair of lines that traps the most water.
pair<int, int> trapping_water(const vector<int>& lines) {
	int volume = 0;
	int left = 0, right = lines.size() - 1;
	int i = 0, j = lines.size() - 1;

	while (i < j) {
		int tmp = (j-i) * min(lines[i], lines[j]);
		if (tmp > volume) {
			volume = tmp;
			left = i;
			right = j;
		}

		if (lines[i] < lines[j]) {
			// Find a taller line on its right side.
			while (lines[++i] <= lines[left] && i < j);
		} else {
			// Find a taller line on its left side.
			while (lines[--j] <= lines[right] && i < j);
		}
	}
	
	return {left, right};
}

int main() {
	//	vector<int> lines{1,2,1,3,4,4,5,6,2,1,3,1,3,2,1,2,4,1};
	vector<int> lines{1,8,6,2,5,4,8,3,7};
	pair<int, int> ret = trapping_water(lines);
	cout << "Lines " << ret.first << ", " << ret.second << ". Volume: "
		 << (ret.second - ret.first) * min(lines[ret.first], lines[ret.second]) << endl;
	return 0;
}
