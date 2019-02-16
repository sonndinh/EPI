#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Compute the medians of an online stream of numbers.
void median() {
	priority_queue<int, vector<int>, greater<int>> min_heap;
	priority_queue<int, vector<int>, less<int>> max_heap;

	int next_num;
	while (cin >> next_num) {
		if (!min_heap.empty() && next_num < min_heap.top()) {
			max_heap.emplace(next_num);
		} else {
			min_heap.emplace(next_num);
		}

		if (min_heap.size() > max_heap.size() + 1) {
			max_heap.push(min_heap.top());
			min_heap.pop();
		}
		
		if (max_heap.size() > min_heap.size() + 1) {
			min_heap.push(max_heap.top());
			max_heap.pop();
		}

		cout << "Median: " << (min_heap.size() == max_heap.size()? 0.5*(min_heap.top()+max_heap.top()) :
							   (min_heap.size() > max_heap.size()? min_heap.top() : max_heap.top())) << endl;
	}
}

// The solution from the book is incorrect. Try sequence: 100 200 50.
// The last median returned is 50, which is wrong because it must be 100.
// The reason is that the code does not guarantee an invariant that
// the top number of the min-heap must be greater-than-or-equal-to the
// top number of the max-heap. 
void epi_sol() {
	priority_queue<int, vector<int>, greater<int>> min_heap;
	priority_queue<int, vector<int>, less<int>> max_heap;

	cin.clear();
	int x;
	while (cin >> x) {
		min_heap.emplace(x);
		if (min_heap.size() > max_heap.size() + 1) {
			max_heap.emplace(min_heap.top());
			min_heap.pop();
		}

		cout << "Median: " << (min_heap.size() == max_heap.size() ?
							   0.5*(min_heap.top() + max_heap.top()) : min_heap.top()) << endl;
	}
}

int main() {
	median();
	cout << "EPI Solution:" << endl;
	epi_sol();
	
	return 0;
}
