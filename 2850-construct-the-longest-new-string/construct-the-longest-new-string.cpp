class Solution {
public:
    int longestString(int x, int y, int z) {
        // xy, yx
        // yz
        // zx

        // xyzxy
        int ans = min(x, y) * 4  + 2 * z;
        if(x != y) ans += 2;
        return ans;
        
    }
};