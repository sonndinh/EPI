// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    char *store = nullptr;
    int start = -1, end = -1;
        
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        // Count is the number of chars returned from new calls to read4..
        // Total is the total number of chars read using read4 in this call to read().
        // From_carry is the number of chars left from previous call to read().
        int count = 0, total = 0, from_carry = 0;
        
        // Retrieve the data from the previous read if any.
        if (store) {
            if (end - start >= n-1) {
                // Have enough data carried over from previous read.
                strncpy(buf, store + start, n);
                start += n;
                if (start > end) {
                    delete[] store;
                    store = nullptr;
                    start = -1; end = -1;
                }
                return n;
            } else {
                // Do not have enough data from previous read.
                strncpy(buf, store + start, end - start + 1);
                n -= end - start + 1;
                from_carry = end - start + 1;
                delete[] store;
                store = nullptr;
                start = -1; end = -1;
            }
        } // if (store)
        
        
        int offset = from_carry;
        while (n) {
            int num = read4(buf + offset);
            total += num;
            if (n >= num) {
                n -= num;
                count += num;
                offset += num;
            } else {
                count += n;
                offset += n;
                n = 0;
            }
            if (num < 4) break;
        }
        
        if (total > count) {
            // Store the unread chars for later read.
            store = new char[total - count];
            start = 0;
            end = total - count - 1;
            strncpy(store, buf + offset, total - count);
        }
        
        return (count + from_carry);
    }
};
