class Solution {
public:
    // approach 1: Bit manipulation, xor with indices
    // O(n) | O(1)
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int mis = n;
        for(int i = 0; i < n; i++) {
            mis ^= (nums[i] ^ i);
        }
        return mis;
    }

    // // approach 1: swap sort, but it will change the original array
    // // O(n) | O(1)
    // int missingNumber(vector<int>& nums) {
    //     int n = nums.size();
    //     for(int i = 0; i < n; i++) {
    //         while(nums[i] != n && nums[i] != i) {
    //             swap(nums[i], nums[nums[i]]);
    //         }
    //     }
    //     // for(int i = 0; i < n; i++) cout << nums[i] << " ";
    //     for(int i = 0; i < n; i++) {
    //         if(i != nums[i]) return i;
    //     }
    //     return n;
    // }


};