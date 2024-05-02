class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> hash;
        for(int num: nums) {
            if(hash.count(-num)) {
                ans = max(ans, abs(num));
            }
            hash.insert(num);
        }
        return ans == 0 ? -1 : ans;
    }
};