#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// Return set of pairs of tasks whose maximum sum is minimized.
// Assuming there are even number of tasks.
vector<pair<unsigned, unsigned>> opt_assign(vector<unsigned>& tasks) {
	vector<pair<unsigned, unsigned>> ret;
	sort(tasks.begin(), tasks.end());
	
	for (int i = 0, j = tasks.size()-1; i < j; ++i, --j) {
		ret.emplace_back(tasks[i], tasks[j]);
	}
	
	return ret;
}

int main() {
	vector<unsigned> tasks{2,3,4,5,6,7};
	auto ret = opt_assign(tasks);
	for (auto& p : ret) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	
	return 0;
}
