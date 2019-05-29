#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Point {
	bool operator== (const Point& that) const {
		return (x == that.x && y == that.y);
	}
	
	int x, y;
};

// Hash function for points.
struct PointHash {
	size_t operator() (const Point& p) const {
		return (hash<int>()(p.x) ^ hash<int>()(p.y));
	}
};

// Compute greatest common divisor of 2 unsigned integers.
unsigned int get_gcd(unsigned int a, unsigned int b) {
	return 0;
}

// Normalized rational numbers. The sign is assigned to the numerator.
struct Rational {
	Rational() {numerator = 0; denominator = 0;}
	
	Rational(int nume, int deno) {
		// Change the sign.
		if ((nume > 0 && deno < 0) || (nume < 0 && deno < 0)) {
			nume = -nume;
			deno = -deno;
		}

		// Normalize the numerator and denominator.
		int gcd = get_gcd(abs(nume), abs(deno));
		numerator = nume/gcd;
		denominator = deno/gcd;
	}
	
	bool operator== (const Rational& that) const {
		return (numerator == that.numerator && denominator == that.denominator);
	}
	
	int numerator, denominator;
};

struct Line {
	Line(const Point& a, const Point& b) {
		int slope_numerator = b.y - a.y;
		int denominator = b.x - a.x;
		int intercept_numerator = b.x * a.y - a.x * b.y;
		
		// Lines that are parallel with y-axis.
		if (denominator == 0) {
			slope = {1, 0};
			intercept = {a.x, 1}; // x-intercept.
		} else {
			slope = Rational(slope_numerator, denominator);
			intercept = Rational(intercept_numerator, denominator);
		}
	}
	
	bool operator== (const Line& that) const {
		return (slope == that.slope && intercept == that.intercept);
	}
	
	Rational slope, intercept;
};

// Hash function for lines.
struct LineHash {
	size_t operator() (const Line& l) const {
		return (hash<int>()(l.slope.numerator) ^ hash<int>()(l.slope.denominator) ^
				hash<int>()(l.intercept.numerator) ^ hash<int>()(l.intercept.denominator));
	}
};

// Return a line that contains the most points.
Line line_through_most(const vector<Point>& A) {
	// Map from each line and its points lying in it.
	unordered_map<Line, unordered_set<Point, PointHash>, LineHash> lines;
	for (int i = 0; i < A.size() - 1; ++i) {
		for (int j = i + 1; j < A.size(); ++j) {
			Line l(A[i], A[j]);
			lines[l].emplace(A[i]);
			lines[l].emplace(A[j]);
		}
	}

	int max_points = 0;
	Line max_line({0, 0}, {0, 0});
	for (auto it = lines.begin(); it != lines.end(); ++it) {
		if (it->second.size() > max_points) {
			max_points = it->second.size();
			max_line = it->first;
		}
	}

	return max_line;
}

int main() {
	return 0;
}
