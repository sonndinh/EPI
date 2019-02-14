#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class CompareTradeTime {
public:
	bool operator() (const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
		return get<1>(a) > get<1>(b);
	}
};

void merge(const vector<vector<int>>& infs, vector<int>& of) {
	// A min heap for storing trade times.
	// Each tuple contains the id of an input file, current trade time, index of next trade time.
	//	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, CompareTradeTime> queue;

	auto compare = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
					   return get<1>(a) > get<1>(b);
				   };
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(compare)> queue(compare);
	
	for (int i = 0; i < infs.size(); i++) {
		if (infs[i].size() > 0) {
			queue.emplace(i, infs[i][0], 1);
		}
	}

	while (!queue.empty()) {
		const tuple<int, int, int>& elem = queue.top();
		int seq_id = get<0>(elem);
		int trade_time = get<1>(elem);
		int next_idx = get<2>(elem);
		// Write the earliest trade time in the priority queue to output sequence.
		of.emplace_back(trade_time);
		
		if (next_idx < infs[seq_id].size()) {
			// Insert the next trade time of the same file to the priority queue.
			queue.emplace(seq_id, infs[seq_id][next_idx], next_idx+1);
		}
		queue.pop();
	}
}

int main() {
	// Simulate 50 files, each contains a list of increasing trade times.
	vector<vector<int>> infiles(50);;
	int fake_time = 0;
	// 10 trade times per file.
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 50; i++) {
			infiles[i].emplace_back(fake_time);
			++fake_time;
		}
	}
	
	vector<int> outfile;
	merge(infiles, outfile);
	if (outfile.size() != 10*50) {
		cout << "ERROR: Wrong size: " << outfile.size() << "!" << endl;
	}
	
	for (int i = 1; i < outfile.size(); i++) {
		if (outfile[i] < outfile[i-1])
			cout << "ERROR: Wrong order: " << endl;
	}
	
	return 0;
}
