#include <iostream>
#include <vector>

using namespace std;

// Return the capacity of a container.
int capacity(const vector<int>& h) {
	if (h.size() == 0) return 0;
	// Store pairs of indices for intervals within which water is trapped.
	vector<int> peaks;
	// Keep track the index corresponding to the max to the left side.
	int max_left = -1;
	int size = h.size();
	for (int i = 1; i < size; i++) {
		// Recognize a peak when the heights start decreasing.
		if (h[i] < h[i-1]) {
			if (max_left == -1) {
				// Store the first peak.
				max_left = i - 1;
				peaks.push_back(i - 1);
			} else if (h[i-1] <= h[peaks.back()]) {
				peaks.push_back(i-1);
				peaks.push_back(i-1);
			} else {
				while (h[i-1] > h[peaks.back()] && peaks.back() != max_left && peaks.size() > 1) {
					peaks.pop_back();
					peaks.pop_back();
				}
				peaks.push_back(i-1);
				peaks.push_back(i-1);
				if (h[i-1] > h[max_left])
					max_left = i - 1;
			}
		}
	}
	// The case when there is a peak at the end of the array.
	if (h[size-1] >= h[size-2]) {
		while (h[size-1] > h[peaks.back()] && peaks.back() != max_left && peaks.size() > 1) {
			peaks.pop_back();
			peaks.pop_back();
		}
		peaks.push_back(size-1);
	}
	
	int total = 0;
	for (int i = 0; i < peaks.size(); i++) {
		if (i+1 < peaks.size()) {
			int left = peaks[i], right = peaks[i+1];
			int bound = h[left] > h[right] ? h[right] : h[left];
			for (int j = left+1; j <= right-1; j++) {
				total += bound - h[j];
			}
		}
	}

	return total;
}

int epi_sol(const vector<int>& h) {
	if (h.size() == 0) return 0;
	int max_idx = 0;
	for (int i = 1; i < h.size(); i++) {
		if (h[i] > h[max_idx]) max_idx = i;
	}

	int total = 0;
	int left = h.front();
	for (int i = 1; i < max_idx; i++) {
		if (h[i] >= left) {
			left = h[i];
		} else {
			total += left - h[i];
		}
	}

	int right = h.back();
	for (int i = h.size()-2; i > max_idx; i--) {
		if (h[i] >= right) {
			right = h[i];
		} else {
			total += right - h[i];
		}
	}
	return total;
}

int main() {
	//	vector<int> h{4, 0, 2, 0, 2};
	//	vector<int> h{6, 1, 5, 2, 3, 2, 4};
	vector<int> h{6, 1, 2, 4, 4, 2, 3, 1, 5, 2};
	int ret = capacity(h);
	cout << "Capacity: " << ret << endl;
	ret = epi_sol(h);
	cout << "EPI solution: " << ret << endl;
	return 0;
}
