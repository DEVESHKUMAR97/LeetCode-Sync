class Solution {
public:
    // O(n * 2^n) | O(n * 2^n)
    // recursion on the way
    void generateSubsets(vector<int> &S, int index, vector<int> &current, vector<vector<int> > &result) {
        if (index >= S.size()) {
            result.push_back(current); // copying the elements
            return;
        }
        // Ignore the current index.
        generateSubsets(S, index + 1, current, result);

        // Include the current index. 
        current.push_back(S[index]);
        generateSubsets(S, index + 1, current, result);
        current.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result; 
        vector<int> current;
        generateSubsets(nums, 0, current, result);
        return result;
    }
};