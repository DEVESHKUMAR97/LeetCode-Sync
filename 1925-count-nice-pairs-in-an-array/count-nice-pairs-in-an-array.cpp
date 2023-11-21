class Solution {
    int rev(int num) {
        int ans = 0;
        while(num > 0) {
            ans = ans * 10 + num % 10;
            num /= 10;
        }
        return ans;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i] = nums[i] - rev(nums[i]);
        }

        long long ans = 0;
        int mod = 1e9+7;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            ans = (ans + mp[vec[i]]) % mod;
            mp[vec[i]]++;
        }
        return ans;
    }
};