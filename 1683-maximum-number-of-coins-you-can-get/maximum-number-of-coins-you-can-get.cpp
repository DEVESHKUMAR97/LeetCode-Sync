class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size() / 3;
        sort(begin(piles), end(piles));
        int ans = 0;
        for(int i = piles.size() - 2; i >= n; i -= 2) {
            ans += piles[i];
        }
        return ans;
        
    }
};