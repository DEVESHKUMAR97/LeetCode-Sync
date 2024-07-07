class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int newBottles = numBottles / numExchange;
        int remainingEmpty = numBottles % numExchange;
        ans += newBottles;
        remainingEmpty += newBottles;
        while(remainingEmpty >= numExchange) {
            newBottles = remainingEmpty / numExchange;
            remainingEmpty = remainingEmpty % numExchange;
            ans += newBottles;
            remainingEmpty += newBottles;
        }
        return ans;
    }
};