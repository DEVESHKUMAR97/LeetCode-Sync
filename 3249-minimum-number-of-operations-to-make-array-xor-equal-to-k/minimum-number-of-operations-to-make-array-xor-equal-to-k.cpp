class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int allXor = 0;
        for(int num : nums) allXor ^= num;
        int bitDiff = allXor ^ k;
        return __builtin_popcount(bitDiff);
    }
};