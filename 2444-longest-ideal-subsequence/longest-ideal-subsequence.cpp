class Solution {
    vector<vector<int>> dp;
    int longestIdealStringStartingFromIndex(int idx, int prevChar, string& s, int k) {
        if(idx == s.length()) return 0;
        int& ans = dp[idx][prevChar-'a'];
        if(ans != -1) return ans;

        // include
        int includeCase = 0;
        if(abs(prevChar - s[idx]) <= k) {
            includeCase = 1 + longestIdealStringStartingFromIndex(idx + 1, s[idx], s, k);
        }

        // exclude
        int excludeCase = longestIdealStringStartingFromIndex(idx + 1, prevChar, s, k);

        return ans = max(includeCase, excludeCase);
    }
public:
    int longestIdealString(string s, int k) {
        dp = vector<vector<int>> (s.length(), vector<int> (26, -1));
        int ans = 0;
        for(int i = 0; i < s.length(); i++) {
            ans = max(ans, 1 + longestIdealStringStartingFromIndex(i+1, s[i], s, k));
        }
        return ans;
    }
};