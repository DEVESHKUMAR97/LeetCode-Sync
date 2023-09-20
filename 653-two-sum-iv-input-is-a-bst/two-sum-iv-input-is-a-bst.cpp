/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void inorder(TreeNode* root, vector<int>& nums) {
        if(!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
public:
    // Approach 2: O(n) | O(n)
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int sum = nums[left] + nums[right];
            if(sum == k) return true;
            if(sum < k) left++;
            else right--;
        }
        return false;
    }


//     // O(log(n))
//     bool search(TreeNode* root, int target) {
//         if(root == nullptr) return false;
//         if(root->val == target) return true;
//         if(root->val < target) return search(root->right, target);
//         return search(root->left, target);
//     }
//     bool dfs(TreeNode* curr, int target, TreeNode* root) {
//         if(curr == nullptr) return false;
//         return search(root, target - curr->val) || dfs(curr->left, target, root) || dfs(curr->right, target, root);
//     }
// public:
//     // Approach 1: O(n * log(n)) | O(log(n)) recursion depth
//     // understood the wrong problem, this solution words when node can be taken twice to make target sum
//     bool findTarget(TreeNode* root, int k) {
//         return dfs(root, k, root);
//     }
};