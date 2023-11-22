class Solution {
public:
    // approach 1: observation diagonal number is same as sum of indices
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> diagonals;
        for(int i = nums.size() - 1; i >= 0; i--) {
            for(int j = 0; j < nums[i].size(); j++) {
                diagonals[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        int currDiagonal = 0;
        while(diagonals.count(currDiagonal)) {
            for(int num: diagonals[currDiagonal]) ans.push_back(num);
            currDiagonal++;
        }
        return ans;
    }
};