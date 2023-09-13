class Solution {
    int numSlots, n;
    vector<int> nums;
    int dp[10][(int)(1<<18)][2];
    int solve(int slotIdx, int numsUsed, int numsInCurrSlot) {
        if(slotIdx == numSlots) {
            return (numsUsed == (1<<n)-1);
        }

        int& cache = dp[slotIdx][numsUsed][numsInCurrSlot];
        if(cache != -1) return cache;

        // exclude
        int ans = solve(slotIdx + 1, numsUsed, 0); // not storing any number in curr slot


        // include
        for(int i = 0; i < n; i++) {
            int currAns = 0;
            if(0 == (int)(numsUsed & (1 << i))) {
                // stored ith num in slotIdx + 1
                currAns += ((slotIdx + 1 ) & nums[i]); 
                
                if(numsInCurrSlot == 0) {
                    // put only ith num in curr slot and next selected number must be put in next slot
                    int ans1 = solve(slotIdx + 1, numsUsed | (1 << i), 0);

                    // next selected number will put in curr slot only
                    int ans2 = solve(slotIdx, numsUsed | (1 << i), 1);

                    currAns += max(ans1, ans2);
                } else {
                    // since this slot already contains one number. So, we are putting ith number in curr Slot
                    currAns += solve(slotIdx + 1, numsUsed | (1 << i), 0);
                }
            }
            ans = max(ans, currAns);
        }
        if(numsInCurrSlot == 0) return cache = ans;
        return cache = ans;
    }
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        this -> numSlots = numSlots;
        this -> nums = nums;
        this -> n = nums.size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0)-1;
        
    }
};