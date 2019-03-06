#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <limits>

using namespace std;

struct Vertex {
	int id;
	vector<pair<int, int>> adjacents;
	int distance;
	int edges;
	int parent;
};

struct Compare {
	bool operator()(const Vertex *lhs, const Vertex *rhs) const {
		return (lhs->distance < rhs->distance);
	}
};

// Input: A directed or undirected graph with non-negative weight edges,
// a source vertex s and a target vertex t.
// Output: A shortest path with fewest number of edges from s to t.
vector<int> sp_fewest_edges(vector<Vertex*>& G, int s, int t) {
	// Init vertices.
	for (Vertex *v : G) {
		if (v->id == s) {
			v->distance = 0;
		} else {
			v->distance = numeric_limits<int>::max();
		}
		v->edges = 0;
		v->parent = -1;
	}

	vector<Vertex*> S(G.size());
	// STL priority_queue does not support key change, so use a set instead.
	set<Vertex*, Compare> Q;
	Q.emplace(G[s]);
	
	while (!Q.empty()) {
		Vertex *u = *Q.cbegin();
		S[u->id] = u;
		Q.erase(Q.cbegin());

		for (const pair<int, int>& p : u->adjacents) {
			Vertex *v = G[p.first];
			int weight = p.second;
			if (v->distance > u->distance + weight) {
				v->distance = u->distance + weight;
				v->edges = u->edges + 1;
				v->parent = u->id;
				Q.emplace(v);
			} else if (v->distance == u->distance + weight && v->edges > u->edges + 1) {
				v->edges = u->edges + 1;
				v->parent = u->id;
				Q.emplace(v);
			}
		}
	}

	// Construct path.
	vector<int> path;
	Vertex *curr = S[t];
	while (curr->parent != -1) {
		path.push_back(curr->id);
		curr = S[curr->parent];
	}
	path.push_back(curr->id);
	return path;
}

int main() {
	Vertex v1{0, {{1, 1}, {2, 4}, {4, 7}}};
	Vertex v2{1, {{3, 5}}};
	Vertex v3{2, {{4, 3}}};
	Vertex v4{3, {{0, 3}, {4, 1}, {5, 3}}};
	Vertex v5{4, {{5, 2}}};
	Vertex v6{5};
	vector<Vertex*> G{&v1, &v2, &v3, &v4, &v5, &v6};
	
	vector<int> path = sp_fewest_edges(G, 0, 5);
	cout << "Shortest path with fewest edges from vertex 0 to 5: ";
	for (int i = path.size()-1; i >= 0; --i) {
		cout << path[i] << " ";
	}
	cout << endl;
	return 0;
}
