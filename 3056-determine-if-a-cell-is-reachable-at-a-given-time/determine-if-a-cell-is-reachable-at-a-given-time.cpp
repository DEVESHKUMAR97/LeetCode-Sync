class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // int diff = abs(sx - fx) + abs(sy - fy);
        // if(sx == fx) {
        //     diff = abs(sy - fy);
        //     t -= diff;
        //     return t >= 0 && t % 2 == 0;
        // }
        // if(sy == fy) {
        //     diff = abs(sx - fx);
        //     t -= diff;
        //     return t >= 0 && t % 2 == 0;
        // }
        int diff1 = abs(sy - fy);
        int diff2 = abs(sx - fx);
        int maxDiff = max(diff1, diff2);
        // int extras = max(diff1, diff2) - minDiff;
        if(maxDiff > t) return false;
        if(maxDiff == 0) return t != 1;
        return true;
        // if(maxDiff == t) return true;
        // t -= maxDiff;
        // return maxDiff == t || (t-maxDiff);
        
        
        
        
    }
};