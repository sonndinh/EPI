#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Compute salary cap. Return -1 if there is no valid cap.
int cap(vector<int>& salaries, int payroll) {
	if (salaries.empty()) return -1;
	
	sort(salaries.begin(), salaries.end());
	int prefix_sum = 0;
	for (int i = -1; i < (int)salaries.size(); ++i) {
		int tmp = (payroll - prefix_sum) / (salaries.size() - i - 1);
		if (i < 0) {
			if (tmp <= salaries[0]) {
				return tmp;
			}
		} else {
			if (tmp >= salaries[i] && (i+1 < salaries.size() ? tmp <= salaries[i+1] : true)) {
				return tmp;
			}
		}

		if (i + 1 < salaries.size()) {
			prefix_sum += salaries[i+1];
		}
	}

	return -1;
}

int main() {
	vector<int> salaries{40, 30, 20, 100, 90};
	int payroll = 210;
	cout << "Cap for salary: " << cap(salaries, payroll) << endl;

	return 0;
}
