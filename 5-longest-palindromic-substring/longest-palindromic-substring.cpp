class Solution {
public:
    string longestPalindrome(string s) {
        // center expansion approach
        int maxLength = 1;
        int startIndex = 0;
        
        for(int c = 0; c < s.length(); c++) {
            int k = 1;
            while(0 <= c - k && c + k < s.length()) {
                if(s[c-k] == s[c+k]) {
                    if(maxLength < k + k + 1) {
                        maxLength = 2 * k + 1;
                        startIndex = c - k;
                    }
                } else {
                    break;
                }
                k++;
            }
        }
        
        for(int c = 0; c < s.length() - 1; c++) {
            int k = 0;
            while(0 <= c - k && c + 1 + k < s.length()) {
                if(s[c-k] == s[c+1+k]) {
                    if(maxLength < k + k + 2) {
                        maxLength = 2 * k + 2;
                        startIndex = c - k;
                    }
                } else {
                    break;
                }
                k++;
            }
        }
        return s.substr(startIndex, maxLength);
        
    }
};