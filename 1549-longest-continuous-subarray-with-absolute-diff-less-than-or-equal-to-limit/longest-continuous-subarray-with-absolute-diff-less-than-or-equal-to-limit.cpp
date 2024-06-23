class Solution {
public:
    int getMinIndexWhileAdding(deque<int>& minQueue, int j, vector<int>& nums) {
        while(minQueue.size() > 0 && nums[minQueue.back()] >= nums[j]) {
            minQueue.pop_back();
        }
        minQueue.push_back(j);
        return minQueue.front();
    }
    int getMaxIndexWhileAdding(deque<int>& maxQueue, int j, vector<int>& nums) {
        while(maxQueue.size() > 0 && nums[maxQueue.back()] <= nums[j]) {
            maxQueue.pop_back();
        }
        maxQueue.push_back(j);
        return maxQueue.front();
    }
    
    int getMinIndexWhileRemoving(deque<int>& minQueue, int i) {
        if(i == minQueue.front()) {
            minQueue.pop_front();
        }
        return minQueue.front();
    }
    int getMaxIndexWhileRemoving(deque<int>& maxQueue, int i) {
        if(i == maxQueue.front()) {
            maxQueue.pop_front();
        }
        return maxQueue.front();
    }
    
    int longestSubarray(vector<int>& nums, int limit) {
        
        deque<int> minQueue, maxQueue;
        
        int i = 0, j = 0;
        int n = nums.size();
        int ans = 1;
        
        while(j < n) {
            int mnIndex = getMinIndexWhileAdding(minQueue, j, nums);
            
            int mxIndex = getMaxIndexWhileAdding(maxQueue, j , nums);
            
            if(nums[mxIndex] - nums[mnIndex] <= limit) {
                ans = max(ans, j - i + 1);
            } else {
                while(nums[mxIndex] - nums[mnIndex] > limit) {
                    mnIndex = getMinIndexWhileRemoving(minQueue, i);
                    mxIndex = getMaxIndexWhileRemoving(maxQueue, i);
                    i++;
                }
            }
            j++;
        }
        return ans;
        
    }
};