class Solution {
public:
    // Approach 2: Using sliding window
    // O(n * log(n))
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> temp(nums.begin(), nums.end());
        vector<int> arr(temp.begin(), temp.end());
        sort(arr.begin(), arr.end());
        int ans = INT_MAX;
        int i = 0, j = 0;
        int m = arr.size();
        while(j < m) {
            if (arr[j] - arr[i] < n - 1) {
                j++;
            } else if(arr[j] - arr[i] == n - 1) {
                ans = min(ans, n - (j - i + 1));
                j++;
            } else {
                while(arr[j] - arr[i] >= n) {
                    ans = min(ans, n - (j-i));
                    i++;
                }
                j++;
            }
        }
        ans = min(ans, n - (j-i));
        return ans;
    }

    // Approach 1: Using binary search
    // O(n * log(n))
    // int minOperations(vector<int>& nums) {
    //     int n = nums.size();
    //     unordered_set<int> temp(nums.begin(), nums.end());
    //     vector<int> arr(temp.begin(), temp.end());
    //     sort(arr.begin(), arr.end());
    //     int ans = INT_MAX;
    //     int nextIdx;
    //     for(int i = 0; i < arr.size(); i++) {
    //         nextIdx = upper_bound(begin(arr), end(arr), arr[i] + n - 1) - begin(arr);
    //         ans = min(ans, n - nextIdx + i);
            
    //     }
    //     return ans;
    // }
};