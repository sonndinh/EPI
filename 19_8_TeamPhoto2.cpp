#include <iostream>
#include <vector>
#include <list>
#include <limits>

using namespace std;

struct Node {
	int id; // Start from 0.
	vector<int> adj;
	bool visited;
	int distance;
};

class DAG {
public:
	DAG(const vector<vector<int>>& t) {
		teams = t;
		int size = t.size();
		for (int i = 0; i < size; i++) {
			sort(teams[i].begin(), teams[i].end());
		}

		nodes.resize(size);
		for (int i = 0; i < size; i++) {
			nodes[i].id = i;
			nodes[i].visited = false;
			nodes[i].distance = 1;
		}

		build_dag();
	}
	
	// Compute the length of longest path.
	int crit_path_len() {
		list<int> topo = topological_sort();
		init_distances();
		
		for (int i : topo) {
			for (int j : nodes[i].adj) {
				// Relax the edge from i to j.
				if (nodes[j].distance < nodes[i].distance + 1) {
					nodes[j].distance = nodes[i].distance + 1;
				}
			}
		}

		int max = 0;
		for (int i : topo) {
			if (nodes[i].distance > max)
				max = nodes[i].distance;
		}
		return max;
	}

private:
	void dfs_visit(Node& node, list<int>& topo) {
		for (int id : node.adj) {
			if (nodes[id].visited == false) {
				dfs_visit(nodes[id], topo);
			}
		}
		node.visited = true;
		topo.push_front(node.id);
	}

	// Return true if A can stand behind B. Input are sorted arrays.
	bool can_be_back(const vector<int>& A, const vector<int>& B) {
		for (int i = 0; i < A.size(); i++) {
			if (A[i] <= B[i])
				return false;
		}
		return true;
	}

	void build_dag() {
		for (int i = 0; i < teams.size()-1; i++) {
			for (int j = i+1; j < teams.size(); j++) {
				if (can_be_back(teams[i], teams[j])) {
					// Add an edge from i to j.
					nodes[i].adj.push_back(j);
				}
				if (can_be_back(teams[j], teams[i])) {
					// Add an edge from j to i.
					nodes[j].adj.push_back(i);
				}
			}
		}
	}

	list<int> topological_sort() {
		list<int> ret;
		for (Node& n : nodes) {
			if (n.visited == false) {
				dfs_visit(n, ret);
			}
		}
		
		return ret;
	}

	void init_distances() {
		// Init distance for all non-source vertices to -infinity.
		for (Node& node : nodes) {
			for (int id : node.adj) {
				nodes[id].distance = numeric_limits<int>::min();
			}
		}
	}
	
private:
	vector<vector<int>> teams;
	vector<Node> nodes;
};

// Find the largest number of teams that can take a photo together.
// Consider each team as a vertex. If team A can stand behind team B, then
// there is an edge from team A to team B. The graph is a DAG since there can
// not be any cycle with the photo constraint. The length of a longest path of
// the DAG is the largest number of teams can take a photo together.
int max_teams(const vector<vector<int>>& teams) {
	DAG dag(teams);
	return dag.crit_path_len();
}

int main() {
	vector<int> A{1, 3, 5, 7, 13, 15};
	vector<int> B{0, 2, 4, 6, 10, 11};
	vector<int> C{-1, 0, 2, 4, 8, 9};
	int ret = max_teams({A, B, C});
	cout << "Largest number of teams: " << ret << endl;

	return 0;
}
