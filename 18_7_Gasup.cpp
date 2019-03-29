#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Return index of an ample city if exists, -1 it not.
// Each pair contains the amount of gas added and distance to the next city.
int gasup(const vector<pair<int, int>>& cities, int mpg) {
	// Find a city with maximum leftover gas after travelling from it
	// to the next city, assuming that it starts from the current city.
	int max_idx = -1; int max_gas_left = numeric_limits<int>::min();
	vector<double> leftover(cities.size());
	
	for (int i = 0; i < cities.size(); i++) {
		double gas_left = cities[i].first - (double) cities[i].second/mpg;
		leftover[i] = gas_left;
		if (gas_left > max_gas_left) {
			max_gas_left = gas_left;
			max_idx = i;
		}
	}

	// Test again if the obtained city is an ample one.
	double gas_tank = 0; // Start with an empty gas tank.
	for (int i = 0; i < cities.size(); i++) {
		int idx = (max_idx + i) % cities.size();
		gas_tank += leftover[idx];
		// If at any point, the leftover gas is negative, then
		// this is not an ample city.
		if (gas_tank < 0) return -1;
	}
	return max_idx;
}

int main() {
	vector<pair<int, int>> cities{{45, 1000}, {10, 200}, {35, 300}, {25, 300}, {25, 300},
								  {20, 300}, {15, 400}, {15, 1000}, {15, 300}, {25, 300},
								  {25, 600}, {30, 400}, {15, 1100}, {55, 400}};
	int mpg = 20;
	int idx = gasup(cities, mpg);
	cout << (idx >= 0 ? "Found ample city. " : "Not found ample city. ");
	if (idx >= 0)
		cout << "Ample city (" << cities[idx].first << ", " << cities[idx].second << ")" << endl;
	return 0;
}
