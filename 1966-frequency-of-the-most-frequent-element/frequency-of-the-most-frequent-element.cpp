class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end(), greater<int>());

        int n = nums.size();

        int left = 0, right = 0; // represents the window with same element nums[left]
        int ans = 0;
        int opsUsed = 0; // operations used

        while(right < n) {
            opsUsed += (nums[left] - nums[right]);
            if(opsUsed <= k) {
                ans = max(ans, right - left + 1);
            } else {
                while(opsUsed > k) {
                    opsUsed -= (nums[left] - nums[left+1]) * (right - left);
                    left++;
                }
                // ans = max(ans, right - left + 1);
            }
            right++;
        }
        return ans;
        
    }
};