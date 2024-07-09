#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxBit = 31;
        vector<int> lastZero(maxBit, -1);

        ll ans = 0;
        for(int i = 0; i < n; i++) {
            int l = -1, r = i;
            int num = nums[i];
            for(int bit = 0; bit < maxBit; bit++) {
                if((num & (1 << bit)) == 0) {
                    lastZero[bit] = i;
                }
                
                if(k & (1 << bit)) { // 1
                    l = max(l, lastZero[bit]);
                } else {
                    r = min(r, lastZero[bit]);
                }
            }
            if(r >= l)
                ans += (r - l);
        }
        return ans;
    }
};

// 1 0 1
// 0 1 1 
// 0 0 0
// 0 0 0