#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Compute the medians of an online stream of numbers.
vector<int> median(const vector<int>& sequence) {
	priority_queue<int, vector<int>, greater<int>> min_heap;
	priority_queue<int, vector<int>, less<int>> max_heap;

	vector<int> ret;
	for (int i = 0; i < sequence.size(); i++) {
		cout << "Here";
		cout << "Top: " << min_heap.top() << endl;
		cout << "There";

		if (sequence[i] < min_heap.top()) {
			max_heap.push(sequence[i]);
		} else {
			min_heap.push(sequence[i]);
		}

		if (min_heap.size() > max_heap.size() + 1) {
			max_heap.push(min_heap.top());
			min_heap.pop();
		}
		
		if (max_heap.size() > min_heap.size() + 1) {
			min_heap.push(max_heap.top());
			max_heap.pop();
		}

		ret.push_back(min_heap.size() == max_heap.size()? (min_heap.top()+max_heap.top())/2 : (min_heap.size() > max_heap.size()? min_heap.top() : max_heap.top()) );
	}
	return ret;
}

int main() {
	vector<int> sequence{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> ret = median(sequence);

	cout << "Running median: ";
	for (auto med : ret) {
		cout << med << " ";
	}
	cout << endl;

	return 0;
}
