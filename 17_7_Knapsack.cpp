#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Each pair contains weight and value of an item.
int knapsack(int w, const vector<pair<int, int>>& items) {
    int n = items.size();
    vector<vector<int>> values(w+1, vector<int>(n, 0));
    for (int j = 1; j <= w; j++) {
        for (int i = 0; i < n; i++) {
            int weight = items[i].first;
            int value = items[i].second;
            int without_item_i = i - 1 < 0 ? 0 : values[j][i-1];
			int with_item_i = j - weight < 0 ? 0 : (i - 1 < 0 ? value : values[j-weight][i-1] + value);

            values[j][i] = max(without_item_i, with_item_i);
        }
    }
    return values[w][n-1];
}

// Return optimal solution.
vector<int> knapsack2(int w, const vector<pair<int, int>>& items) {
    int n = items.size();
    vector<vector<pair<int, bool>>> values(w+1, vector<pair<int, bool>>(n, {0, false}));

    for (int j = 1; j <= w; j++) {
        for (int i = 0; i < n; i++) {
            int weight = items[i].first;
            int value = items[i].second;
            int without_item_i = i - 1 < 0 ? 0 : values[j][i-1].first;
            int with_item_i = j - weight < 0 ? 0 : (i - 1 < 0 ? value : values[j-weight][i-1].first + value);
            
            if (without_item_i < with_item_i) {
                values[j][i].first = with_item_i;
                values[j][i].second = true;
            } else {
                values[j][i].first = without_item_i;
                values[j][i].second = false;
            }
        }
    }

    vector<int> sol;
    int j = w, i = n - 1;
    while(j >= 0 && i >= 0) {
        if (values[j][i].second) {
            // Item i is included.
            sol.emplace_back(i);
            j -= items[i].first;
            i--;
        } else {
            i--;
        }
    }
    
    return sol;
}

int main() {
	vector<pair<int, int>> items{{20, 65}, {8, 35}, {60, 245}, {55, 195}, {40, 65}, 
                                 {70, 150}, {85, 275}, {25, 155}, {30, 120}, 
                                 {65, 320}, {75, 75}, {10, 40}, {95, 200}, 
                                 {50, 100}, {40, 220}, {10, 99}};
    int w = 130;
	/*
    int ret1 = knapsack(w, items);
    cout << "Max value of knapsack: " << ret1 << endl;
	*/
	vector<int> ret2 = knapsack2(w, items);
    int val = 0;
    cout << "Knapsack contains items: ";
    for (int i = ret2.size()-1; i >= 0; i--) {
        cout << ret2[i] << " ";
        val += items[ret2[i]].second;
    }
    cout << ". Total value: " << val << endl;
	
	return 0;
}
