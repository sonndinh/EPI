#include <vector>
#include <iostream>

using namespace std;


void swap(int& a, int& b, int& c, int& d) {
	int tmp1 = a, tmp2 = b;
	a = d;
	b = tmp1;
	tmp1 = c;
	c = tmp2;
	d = tmp1;
}

// Rotate a 2D array 90 degree clockwise.
// In-place rotation requires square array.
void rotate(vector<vector<int>>& arr) {
	int n = arr.size();
	int layer = (n+1)/2;
	
	for (int k = 0; k < layer; k++) {
		int b = k; // lower index
		int t = n - 1 - k; // upper index
		for (int i = b; i < t; i++) {
			swap(arr[b][i], arr[i][t], arr[t][t-i+b], arr[t-i+b][b]);
		}
	}
}

void print(const vector<vector<int>>& arr) {
	for (auto& row : arr) {
		for (auto& i : row) {
			cout << i <<  "\t";
		}
		cout << endl;
	}
}

int main() {
	//	vector<vector<int>> arr{{1,2,3}, {5,6,7}, {9,10,11}};
	//	vector<vector<int>> arr{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
	int n;
	cout << "Enter array dimension:";
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n));
	int num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = num++;
		}
	}
		
	cout << "Original array:\n";
	print(arr);
	rotate(arr);
	cout << "Rotated array:\n";
	print(arr);
	return 0;
}
