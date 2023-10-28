class Solution {
public:
    int countVowelPermutation(int n) {
      int mod = 1e9+7;
      long long dp[n][5];
      for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < 5; j++) {
          if(i == n - 1) {
            dp[i][j] = 1;
          } else {
            
            if(j == 0) {
              // ith char is a
              dp[i][j] = dp[i+1][1];
            } else if(j == 1) {
              // ith char is e
              dp[i][j] = (dp[i+1][0] + dp[i+1][2]) % mod;

            } else if(j == 2) {
              // ith char is i
              dp[i][j] = (dp[i+1][0] + dp[i+1][1] + dp[i+1][3] + dp[i+1][4]) % mod;

            } else if(j == 3) {
              // ith char is o
              dp[i][j] = (dp[i+1][2] + dp[i+1][4]) % mod;

            } else if(j == 4) {
              // ith char is u
              dp[i][j] = dp[i+1][0];

            }
          }
        }
        
      }
        
      return (dp[0][0] + dp[0][1] + dp[0][2] + dp[0][3] + dp[0][4]) % mod;
    }
};