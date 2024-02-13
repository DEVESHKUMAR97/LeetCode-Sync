class Solution {
    bool isPal(string& s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(string& w: words) {
            if(isPal(w)) {
                return w;
            }
            
        }
        return "";
    }
};