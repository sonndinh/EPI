#include <iostream>
#include <vector>
using namespace std;

struct Skyline {
	int left, right, height;
	Skyline(int l, int r, int h) : left(l), right(r), height(h) {}
};

vector<Skyline> merge_halves(const vector<Skyline>& l_half, const vector<Skyline>& r_half) {
	vector<Skyline> ret;
	int left_coor = min(l_half[0].left, r_half[0].left);

	int i, j;
	for (i = 0, j = 0; i < l_half.size() && j < r_half.size();) {
		int right_coor; // The next coordinate.
		int height;
		if (left_coor == l_half[i].left) {
			if (left_coor == r_half[j].left) {
				right_coor = min(l_half[i].right, r_half[j].right);
				height = max(l_half[i].height, r_half[j].height);
			} else {
				if (left_coor >= r_half[j].left)
					right_coor = min(l_half[i].right, r_half[j].right);
				else 
					right_coor = min(l_half[i].right, r_half[j].left);
				height = l_half[i].height;
			}
		} else { // left_coor == r_half[j].left
			if (left_coor == l_half[i].left) {
				right_coor = min(r_half[j].right, l_half[i].right);
				height = max(l_half[i].height, r_half[j].height);
			} else {
				if (left_coor >= l_half[i].left)
					right_coor = min(r_half[j].right, l_half[i].right);
				else
					right_coor = min(r_half[j].right, l_half[i].left);
				height = r_half[j].height;
			}
		}

		cout << "Inserting: (" << left_coor << "," << right_coor << "," << height << ")" << endl;
		ret.emplace_back(left_coor, right_coor, height);
		left_coor = right_coor;
		if (left_coor == l_half[i].right) {
			i++;
		}
		if (left_coor == r_half[j].right) {
			j++;
		}
	}
	if (i == l_half.size()) {
		if (r_half.back().left > left_coor) {
			ret.emplace_back(left_coor, r_half.back().left, 0);
			ret.emplace_back(r_half.back());
		} else if (r_half.back().right > left_coor) {
			ret.emplace_back(left_coor, r_half.back().right, r_half.back().height);
		}
	} else { //j == r_half.size()
		if (l_half.back().left > left_coor) {
			ret.emplace_back(left_coor, l_half.back().left, 0);
			ret.emplace_back(l_half.back());
		} else if (l_half.back().right > left_coor) {
			ret.emplace_back(left_coor, l_half.back().right, l_half.back().height);
		}
	}
	return ret;
}

void print(const vector<Skyline>& A) {
	for (auto& line : A) {
		cout << "(" << line.left << "," << line.right << "," << line.height << ") ";
	}
	cout << endl;
}

vector<Skyline> draw_skyline_helper(const vector<Skyline>& lines, int s, int e) {
	if (s >= e) {
		return vector<Skyline>();
	} else if (e == s + 1) {
		return vector<Skyline>{lines[s]};
	}

	int mid = s + (e-s)/2;
	vector<Skyline> left_half = draw_skyline_helper(lines, s, mid);
	cout << "Left half: "; print(left_half);
	vector<Skyline> right_half = draw_skyline_helper(lines, mid, e);
	cout << "Right half: "; print(right_half);
	return merge_halves(left_half, right_half);
}

vector<Skyline> draw_skyline(const vector<Skyline>& lines) {
	return draw_skyline_helper(lines, 0, lines.size());
}

int main() {
	vector<Skyline> lines{{0, 2, 2}, {1, 6, 4}, {4, 10, 2}, {8, 15, 6}};
	//vector<Skyline> lines{{0, 2, 2}, {1, 6, 4}};
	auto ret = draw_skyline(lines);
	print(ret);
	return 0;
}
