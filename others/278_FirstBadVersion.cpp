// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // Find the first version for which isBadVersion return true.
        int start = 1, end = n;
        while (start < end) {
            int mid = start + (end - start)/2;
            if (isBadVersion(mid) == false) {
                start = mid + 1;
            } else {
                if (!isBadVersion(mid-1)) return mid;
                end = mid - 1;
            }
        }
        return start;
    }
};
