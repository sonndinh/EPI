class Solution {
private:
    bool visit(vector<vector<char>>& board, int i, int j, string& word, int idx, vector<vector<bool>>& visited) {
        if (board[i][j] != word[idx])
            return false;
        
        if (idx == word.size()-1)
            return true;
        
        visited[i][j] = true;
        int n = board.size(), m = board[0].size();
        vector<vector<int>> neighbors{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (vector<int>& offset : neighbors) {
            int x = i + offset[0], y = j + offset[1];
            if (x >= 0 && x < n && y >= 0 && y < m && visited[x][y] == false) {
                if (visit(board, x, y, word, idx+1, visited))
                    return true;
            }
        }
        visited[i][j] = false;
        
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty())
            return true;
        
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visit(board, i, j, word, 0, visited))
                    return true;
            }
        }
        return false;
    }
};
