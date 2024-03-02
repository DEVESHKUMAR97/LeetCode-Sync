class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i = 0, j = nums.size() - 1;
        int k = j;
        while(i <= j) {
            if(nums[i] * nums[i] >= nums[j] * nums[j]) {
                ans[k--] = nums[i] * nums[i];
                i++;
            } else {
                ans[k--] = nums[j] * nums[j];
                j--;
            }
        }
        return ans;
        
    }
};