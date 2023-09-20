class Solution {
public:
    // O(n*log(n) + n^2) | O(1)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // O(n * log(n))

        int target;
        int left, right, pairSum;
        vector<vector<int>> ans;
        for(int i = 0; i + 2 < n; i++) {
            target = -nums[i];
            left = i + 1, right = n - 1;
            while(left < right) {
                pairSum = nums[left] + nums[right];
                if(pairSum == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left-1]) left++; // skipping all same candidates for 2nd position
                    while(right > left && nums[right] == nums[right+1]) right--; // skipping all same candidates for 3rd position
                } else if(pairSum < target) {
                    left++;
                } else {
                    right--;
                }
            }

            while(i + 1 < n && nums[i] == nums[i+1]) i++; // skipping all same candidates for 1st position
        }

        return ans;
        
    }
};