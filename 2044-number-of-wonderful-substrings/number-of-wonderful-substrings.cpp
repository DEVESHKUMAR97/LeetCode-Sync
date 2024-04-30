class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int> maskFreq;
        int mask = 0;
        maskFreq[mask]++;
        long long ans = 0;
        for(char ch: word) {
            mask ^= (1 << (ch-'a'));

            ans += maskFreq[mask];

            maskFreq[mask]++;

            for(int i = 0; i < 10; i++) {
                ans += maskFreq[mask ^ (1 << i)];
            }

        }
        return ans;
        
    }
};