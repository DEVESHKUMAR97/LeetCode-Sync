#define ll long long
class Solution {
    const int mod = (int)1e9+7;
    ll dp[51][51][101];
    ll add(ll a, ll b) {
        return ((a%mod)+(b%mod))%mod;
    }
    ll mul(ll a, ll b) {
        return ((a%mod)*(b%mod))%mod;
    }

    /*
    n : 0 -> n
    maxTillNow : 0 -> m
    k : 0 -> k

    Earlier time in each state : O(m)
    Now, after loop caching dp optimization. Time in each state: O(1)
    So, overall time complexity : O(n * m * k)

    solve(n, k, maxTillNow)
    = maxTillNow * 


    */

    ll solve(int n, int k, int maxTillNow, int m) {
        if(n == 0) {
            if(k == 0) return 1;
            return 0;
        }
        
        ll& ans = dp[n][k][maxTillNow];
        if(ans != -1) return ans;
        ans = 0;
        // for(int curr = 1; curr <= maxTillNow; curr++) {
        //     ans = add(ans, solve(n-1, k, maxTillNow, m));
        // }
        // In above loop all the child states are same. So, we can avoid that loop
        ans = mul(maxTillNow, solve(n-1, k, maxTillNow, m));


        if(k > 0) {
            for(int curr = maxTillNow + 1; curr <= m; curr++) {
                ans = add(ans, solve(n-1, k-1, curr, m));
            }
        }
        return ans;

    }
public:
    // Approach 2: Optimization of loop per state
    // Time : O(n * k * m)
    // Space : O(n * k * m)
    int numOfArrays(int n, int m, int k) {
        if(k == 0) return 0;
        memset(dp, -1, sizeof(dp));
        return solve(n, k, 0, m);
    }
};