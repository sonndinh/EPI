// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int count = 0;
        while (n) {
            int num_chars = read4(buf+count);
            if (num_chars >= n) {
                count += n;
                n = 0;
            } else {
                count += num_chars;
                n -= num_chars;
            }
            
            if (num_chars < 4) {
                break;
            }
        }
        return count;
    }
};
