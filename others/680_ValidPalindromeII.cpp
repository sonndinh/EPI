class Solution {
private:
    bool isPalindromic(string& s) {
        int n = s.size();
        for (int i = 0, j = n-1; i < j; ++i, --j) {
            if (s[i] != s[j]) 
                return false;
        }
        return true;
    }
    
    // Can we remove a character in s[s1:e1] to make the string palindromic?
    // s[s1:e1] is 1 character longer than s[s2:e2].
    bool isRemovable(string& s, int s1, int e1, int s2, int e2) {
        if (s2 > e2) {
            // Base case - the second substring is empty, the first one has 1 character.
            return true;
        }
        
        int count_remove = 1;
        for (int i = s1, j = e2; i <= e1 && j >= s2;) {
            if (s[i] != s[j]) {
                if (count_remove == 0) {
                    return false;
                } else { // Remove this character.
                    count_remove = 0;
                    ++i;
                }
            } else { // Match, go to the next pair.
                ++i;
                --j;
            }
        }
        return true;
    }
    
public:
    bool validPalindrome(string s) {
        if (isPalindromic(s))
            return true;
        
        // Need to remove 1 character.
        int n = s.size();
        if (n % 2 == 0) { // Even number of chracters.
            if (isRemovable(s, 0, n/2-1, n/2+1, n-1)) { // If remove on the first half.
                return true;
            }
            return isRemovable(s, n/2, n-1, 0, n/2-2);
        } else { // Odd number of characters.
            if (isRemovable(s, 0, n/2, n/2+1, n-1)) {
                return true;
            }
            return isRemovable(s, n/2, n-1, 0, n/2-1);
        }
    }
};
