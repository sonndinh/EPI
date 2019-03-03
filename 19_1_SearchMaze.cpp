#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
// Store each pixel's coordinates.
using Pos = pair<int, int>;

vector<Pos> get_neighbors(Pos node) {
	int x = node.first, y = node.second;
	vector<Pos> ret;
	ret.emplace_back(x-1, y);
	ret.emplace_back(x+1, y);
	ret.emplace_back(x, y-1);
	ret.emplace_back(x, y+1);
	return ret;
}

// DFS visit nodes.
bool dfs_visit(const vector<vector<int>>& maze, vector<Pos>& path, Pos node, vector<vector<bool>>& visited) {
	path.emplace_back(node.first, node.second);
	visited[node.first][node.second] = true;
	if (maze[node.first][node.second] == 2) return true;

	int m = maze.size(), n = maze[0].size();
	vector<Pos> neighbors = get_neighbors(node);
	for (Pos neigh : neighbors) {
		if (neigh.first >= 0 && neigh.first <= m-1 && neigh.second >= 0 && neigh.second <= n-1 &&
			maze[neigh.first][neigh.second] != 1 && visited[neigh.first][neigh.second] == false) {
			if (dfs_visit(maze, path, neigh, visited))
				return true;
		}
	}
	path.pop_back();
	return false;
}

// Need to construct path.
bool bfs(const vector<vector<int>>& maze, vector<Pos>& path, Pos source, vector<vector<bool>>& visited) {
	queue<Pos> frontier;
	frontier.push(source);
	while (!frontier.empty()) {
		Pos node = frontier.front();
		frontier.pop();
		visited[node.first][node.second] = true;
		if (maze[node.first][node.second] == 2) return true;
		
		vector<Pos> neighbors = get_neighbors(node);
		for (Pos p: neighbors) {
			if (p.first >= 0 && p.first < maze.size() && p.second >= 0 && p.second < maze[0].size() &&
				maze[p.first][p.second] != 1 && visited[p.first][p.second] == false)
				frontier.push(p);
		}
	}
	
	return false;
}

// Find a path from an entrance to an exit of a maze.
// 0 pixels are free. 1 pixels are wall. 2 pixel is the exit.
vector<Pos> search_path(const vector<vector<int>>& maze, Pos s) {
	// Store for each pixel whether it is visited.
	vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
	vector<Pos> path;
	dfs_visit(maze, path, s, visited);
	return path;
}

int main() {
	vector<vector<int>> maze = {{0, 1, 0}, {0, 0, 1}, {1, 0, 2}};
	int ent_row = 0, ent_col = 0;
	vector<Pos> path = search_path(maze, make_pair(ent_row, ent_col));
	cout << (path.size() > 0 ? "Path: " : "Not found path.");
	for (Pos p : path) {
		cout << "(" << p.first << "," << p.second << ") ";
	}
	cout << endl;
	return 0;
}
