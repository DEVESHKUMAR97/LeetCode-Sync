class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumFreq;
        prefixSumFreq[0] = 1;
        int prefixSum = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            if(prefixSumFreq.count(prefixSum - k)) {
                ans += prefixSumFreq[prefixSum - k];
            }
            prefixSumFreq[prefixSum]++;
        }
        return ans;
    }
};