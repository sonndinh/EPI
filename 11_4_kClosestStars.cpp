#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

// Alias for stars's coordinates.
using coordinate_t = tuple<int, int, int>;

// For comparing distance to Earth.
struct Compare {
	bool operator() (const coordinate_t& a, const coordinate_t& b) {
		int x_a = get<0>(a), y_a = get<1>(a), z_a = get<2>(a);
		int x_b = get<0>(b), y_b = get<1>(b), z_b = get<2>(b);
		return (sqrt(x_a*x_a + y_a*y_a + z_a*z_a) > sqrt(x_b*x_b + y_b*y_b + z_b*z_b));
	}
};

vector<coordinate_t> k_closest(const vector<coordinate_t>& arr, int k) {
	priority_queue<coordinate_t, vector<coordinate_t>, Compare> queue(Compare(), arr);
	vector<coordinate_t> ret;
	for (int i = 0; i < k; i++) {
		ret.push_back(queue.top());
		queue.pop();
	}
	return ret;
}

int main() {
	vector<coordinate_t> stars = {{1,2,3}, {4,5,6}, {7,8,9}, {1,0,-1}, {2,0,2}};
	int k = 2;
	vector<coordinate_t> closest = k_closest(stars, k);
	cout << k << " Closest stars: ";
	for (auto star : closest) {
		cout << "(" << get<0> (star) << "," << get<1> (star) << "," << get<2> (star) << "), ";
	}
	cout << endl;
	
	return 0;
}
