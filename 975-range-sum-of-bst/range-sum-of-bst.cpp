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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return 0;
        int ans = 0;
        if(root->val >= low && root->val <= high) {
            ans += root->val;
            ans += rangeSumBST(root->left, low, high);
            ans += rangeSumBST(root->right, low, high);
        } else if(root->val < low) {
            ans += rangeSumBST(root->right, low, high);
        } else {
            ans += rangeSumBST(root->left, low, high);
        }
        return ans;
    }
};