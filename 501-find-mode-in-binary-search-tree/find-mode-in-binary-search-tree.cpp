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
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> values;
        dfs(root, values);
        
        int maxStreak = 0;
        int currStreak = 0;
        int currNum = 0;
        vector<int> ans;
        
        for (int num : values) {
            if (num == currNum) {
                currStreak++;
            } else {
                currStreak = 1;
                currNum = num;
            }
            
            if (currStreak > maxStreak) {
                ans = {};
                maxStreak = currStreak;
            }
            
            if (currStreak == maxStreak) {
                ans.push_back(num);
            }
        }
        
        return ans;
    }
    
    void dfs(TreeNode* node, vector<int>& values) {
        if (node == nullptr) {
            return;
        }
        
        // Inorder traversal visits nodes in sorted order
        dfs(node->left, values);
        values.push_back(node->val);
        dfs(node->right, values);
    }
};