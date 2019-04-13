#include <iostream>
#include <vector>
using namespace std;

struct Skyline {
	int left, right, height;
	Skyline(int l, int r, int h) : left(l), right(r), height(h) {}
};

// EPI solution.
void merge_intersect(vector<Skyline>& merged, Skyline& a, int& a_idx, Skyline& b, int& b_idx) {
	if (a.right <= b.right) {
		if (a.height > b.height) {
			if (b.right != a.right) {
				merged.emplace_back(a);
				++a_idx;
				b.left = a.right;
			} else {
				++b_idx;
			}
		} else if (a.height == b.height) {
			b.left = a.left;
			++a_idx;
		} else {
			if (a.left != b.left) {
				merged.emplace_back(Skyline(a.left, b.left, a.height));
			}
			++a_idx;
		}
	} else {
		if (a.height >= b.height) {
			++b_idx;
		} else {
			if (a.left != b.left) {
				merged.emplace_back(Skyline(a.left, b.left, a.height));
			}
			a.left = b.right;
			merged.emplace_back(b);
			++b_idx;
		}
	}
}

// EPI solution.
vector<Skyline> merge(vector<Skyline>& L, vector<Skyline>& R) {
	int i = 0, j = 0;
	vector<Skyline> merged;

	while (i < L.size() && j < R.size()) {
		if (L[i].right < R[j].left) {
			merged.emplace_back(L[i++]);
		} else if (R[j].right < L[i].left) {
			merged.emplace_back(R[j++]);
		} else if (L[i].left <= R[j].left) {
			merge_intersect(merged, L[i], i, R[j], j);
		} else {
			merge_intersect(merged, R[j], j, L[i], i);
		}
	}

	merged.insert(merged.end(), L.cbegin() + i, L.cend());
	merged.insert(merged.end(), R.cbegin() + j, R.cend());
	return merged;
}

// Todo: incorrect result.
vector<Skyline> merge_halves(const vector<Skyline>& l_half, const vector<Skyline>& r_half) {
	vector<Skyline> ret;
	int left_coor = min(l_half[0].left, r_half[0].left);

	int i, j;
	for (i = 0, j = 0; i < l_half.size() && j < r_half.size();) {
		int right_coor; // The next coordinate.
		if (left_coor == l_half[i].left) {
			if (left_coor == r_half[j].left) {
				right_coor = min(l_half[i].right, r_half[j].right);
			} else {
				if (left_coor >= r_half[j].left)
					right_coor = min(l_half[i].right, r_half[j].right);
				else 
					right_coor = min(l_half[i].right, r_half[j].left);
			}
		} else { // left_coor == r_half[j].left
			if (left_coor == l_half[i].left) {
				right_coor = min(r_half[j].right, l_half[i].right);
			} else {
				if (left_coor >= l_half[i].left)
					right_coor = min(r_half[j].right, l_half[i].right);
				else
					right_coor = min(r_half[j].right, l_half[i].left);
			}
		}

		ret.emplace_back(left_coor, right_coor, 0);
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

	// Compute heights.
	i = 0, j = 0;
	int k;
	for (k = 0; k < ret.size() && i < l_half.size() && j < r_half.size(); ++k) {
		int l = ret[k].left, r = ret[k].right;
		int tmp;
		if (l_half[i].left <= l && l_half[i].right >= r)
			tmp = l_half[i].height;
		if (r_half[j].left <= l && r_half[j].right >= r)
			tmp = max(tmp, r_half[j].height);
		ret[k].height = tmp;
		
		if (l_half[i].right <= r)
			++i;
		if (r_half[j].right <= r)
			++j;
	}
	if (i == l_half.size() && j < r_half.size()) {
		for (; k < ret.size(); ++k) {
			ret[k].height = r_half[j].height;
			++j;
		}
	} else {
		for (; k < ret.size(); ++k) {
			ret[k].height = l_half[i].height;
			++i;
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
	vector<Skyline> L = draw_skyline_helper(lines, s, mid);
	vector<Skyline> R = draw_skyline_helper(lines, mid, e);
	//return merge_halves(L, R);
	return merge(L, R);
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
