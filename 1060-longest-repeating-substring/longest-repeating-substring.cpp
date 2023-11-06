class Solution {
public:
    int longestRepeatingSubstring(string s) {

        int dp[s.length()][s.length()];
        memset(dp, -1, sizeof(dp));

        function<int(int, int)> solve = [&](int i, int j) {
            if(i == s.length() || j == s.length()) return 0;

            int& ans = dp[i][j];
            if(ans != -1) return ans;

            if(i != j && s[i] == s[j]) {
                ans = 1 + solve(i+1, j+1);
            } else {
                ans = 0;
            }
            return ans;
        };
        int ans = INT_MIN;
        for(int i = 0; i < s.length(); i++) for(int j = 0; j < s.length(); j++) {
            ans = max(ans, solve(i, j));
        }
        return ans;
        
    }
};