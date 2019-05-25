#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;

struct CustomLess {
	bool operator() (const tuple<string&, int, int>& a, const tuple<string&, int, int>& b) {
		int start_a = get<1>(a), end_a = get<2>(a);
		int start_b = get<1>(b), end_b = get<2>(b);
		return (get<0>(a).compare(start_a, end_a - start_a + 1, get<0>(b), start_b, end_b - start_b + 1) < 0);
	}
};

// Sort a string consists of lines delimitered by null characters.
string variable_length_sort(string& text) {
	vector<tuple<string&, int, int>> lines;
	int start = 0;
	for (int i = 0; i < text.size(); ++i) {
		if (text[i] == '\0') {
			lines.emplace_back(make_tuple(text, start, i));
			start = i+1;
		}
	}
	// Last line may not be followed by a null character.
	if (start < text.size()) {
		lines.emplace_back(make_tuple(text, start, text.size()-1));
	}

	CustomLess less;
	sort(lines.begin(), lines.end(), less);

	// Copy to the resulting string.
	string s;
	for (auto& t : lines) {
		int start = get<1>(t), end = get<2>(t);
		s += text.substr(start, end - start + 1);
	}
	
	return s;
}

int main() {
	string text = "hahahaha\0kekekeke\0ohohohoh\0";
	string sorted_text = variable_length_sort(text);
	cout << "Original: " << text << endl;
	cout << "Sorted:   " << sorted_text << endl;
	return 0;
}
