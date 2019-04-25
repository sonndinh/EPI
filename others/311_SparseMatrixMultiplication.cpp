class Solution {
private:
    vector<vector<pair<int,int>>> convertRowise(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<pair<int, int>>> ret(n);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (A[i][j] != 0) {
                    ret[i].emplace_back(j, A[i][j]);
                }
            }
        }
        return ret;
    }
    
    vector<vector<pair<int, int>>> convertColumnwise(vector<vector<int>>& B) {
        int m = B[0].size(), n = B.size();
        vector<vector<pair<int, int>>> ret(m);
        
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (B[i][j] != 0) {
                    ret[j].emplace_back(i, B[i][j]);
                }
            }
        }
        return ret;
    }
    
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<pair<int, int>>> A2 = convertRowise(A);
        vector<vector<pair<int, int>>> B2 = convertColumnwise(B);
        
        // Number of rows and columns of the output matrix.
        int nA = A.size();
        int mB = B[0].size();
        // Initialize all elements to 0.
        vector<vector<int>> ret(nA, vector<int>(mB, 0));
        
        for (int i = 0; i < nA; ++i) {
            for (int j = 0; j < mB; ++j) {
                // Multiply row i-th of A2 with column j-th of B2.
                if (A2[i].size() != 0 && B2[j].size() != 0) {
                    int sum = 0;
                    vector<pair<int, int>>& rowA = A2[i];
                    vector<pair<int, int>>& colB = B2[j];
                    for (int k = 0, l = 0; k < rowA.size() && l < colB.size();) {
                        if (rowA[k].first == colB[l].first) {
                            sum += rowA[k].second * colB[l].second;
                            ++k;
                            ++l;
                        } else if (rowA[k].first > colB[l].first) {
                            ++l;
                        } else {
                            ++k;
                        }
                    }
                    
                    ret[i][j] = sum;
                }
            }
        }
        
        return ret;
    }
};
