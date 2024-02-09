class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> dp(n, 1), dpTable(n);
        for(int i = 0; i < n; i++) {
            dpTable[i] = i;
            for(int j = i - 1; j >= 0; j--) {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    dpTable[i] = j;
                }
            }
        }

        int startIdx = max_element(dp.begin(), dp.end()) - dp.begin();
        vector<int> ans;
        while(startIdx != dpTable[startIdx]) {
            ans.push_back(nums[startIdx]);
            startIdx = dpTable[startIdx];
        }
        ans.push_back(nums[startIdx]);
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};