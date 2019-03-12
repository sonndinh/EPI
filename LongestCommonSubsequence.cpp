#include <iostream>
#include <vector>
using namespace std;

string lcs(const string& A, const string& B) {
    int n = A.size(), m = B.size();
    if (n == 0 || m == 0) return "";
    
    vector<vector<int>> table(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                table[i][j] = 1 + (i < 1 || j < 1 ? 0 : table[i-1][j-1]);
            } else {
                int p = (i < 1 ? 0 : table[i-1][j]);
                int q = (j < 1 ? 0 : table[i][j-1]);
                table[i][j] = max(p, q);
            }
        }
    }
    
    // Reconstruct the longest common subsequence.
    int len = table[n-1][m-1];
    string ret(len, ' ');
    int i = n-1, j = m-1;
    while (len > 0) {
        if (A[i] == B[j]) {
            ret[len-1] = A[i];
            --i; --j; --len;
        } else if (table[i-1][j] > table[i][j-1]) {
            --i;
        } else {
            --j;
        }
    }
    return ret;
}

int main() {
    string A = "accggtcgagtgcgcggaagccggccgaa";
    string B = "gtcgttcggaatgccgttgctctgtaaa";
    //string A = "10010101";
    //string B = "010110110";
    string ret = lcs(A, B);
    cout << "String A: " << A << endl;
    cout << "String B: " << B << endl;
    cout << "Longest Common Subsequence: " << ret << endl;
    return 0;
}
