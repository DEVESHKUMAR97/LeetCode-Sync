class Solution {
public:
    // approach 2: O(log(n))
    int mySqrt(int x) {
        long long low = 0, high = 1e5;
        long long mid;

        int ans;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(mid * mid <= x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    // approach 1: O(sqrt(n))
    // int mySqrt(int x) {
    //     long long ans = -1;
    //     long long i = 0;
    //     while(i*i<=x) {
    //         ans = i;
    //         i++;
    //     }
    //     return ans;
    // }
};