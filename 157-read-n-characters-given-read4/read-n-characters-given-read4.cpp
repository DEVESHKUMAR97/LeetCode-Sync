/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int ans = 0;
        int charsRead = read4(buf);
        while(charsRead != 0) {
            ans += charsRead;
            charsRead = read4(buf + ans);
        }
        return n;

    }
};