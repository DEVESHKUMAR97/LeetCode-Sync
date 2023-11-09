class Solution {
    int mod = 1e9+7;
    long long add(long long a, long long b) {
        return (a + b) % mod;
    }

    long long mul(long long a, long long b) {
        return (a * b) % mod;
    }
public:
    int countHomogenous(string s) {
        int ans = 0;
        
        int firstIdx = 0;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] != s[firstIdx]) {
                // cout << firstIdx << " " << i;
                long long len = i - firstIdx;
                ans = add(ans, len * (len + 1) / 2);
                // cout << " => " << ans << endl;
                firstIdx = i;
            }
        }
        long long len = s.length() - firstIdx;
        ans = add(ans, len * (len + 1) / 2);
        return ans;
    }
};